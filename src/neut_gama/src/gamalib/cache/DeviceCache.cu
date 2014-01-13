/*
 * DeviceCache.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: jbarbosa
 */

#include <cuda.h>
#include <driver_types.h>
#include <helper_cuda.h>
#include <config/common.h>
#include <gamalib/utils/x86_utils.h>

#include <boost/icl/interval.hpp>
#include <boost/icl/interval_set.hpp>
#include <boost/icl/split_interval_set.hpp>
#include <boost/icl/closed_interval.hpp>
#include <boost/icl/right_open_interval.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include "DeviceCache.h"

#include <cstdio>
#include <cstdlib>

using namespace std;
using namespace boost::icl;

DeviceCache::DeviceCache()
{
	//get the amount of free memory on the graphics card
	size_t free;
	size_t total;
	checkCudaErrors(cudaMemGetInfo(&free,&total));

	if (free < CACHE_SIZE) {
		fprintf(stderr,"Out of GPU memory\n");
		exit(0);
	}

	checkCudaErrors(cudaMalloc((void**)&cache,CACHE_SIZE));
	checkCudaErrors(cudaMemcpyToSymbol(_cache,&cache,sizeof(void*)));

	dcache = cache;
}

DeviceCache::~DeviceCache()
{
	// TODO Auto-generated destructor stub
}

bool DeviceCache::cachePtr(void* ptr, size_t size, cudaStream_t* st) {
	boost::mutex::scoped_lock lock(_lock);
	boost::icl::right_open_interval<_ulong> r((_ulong)ptr,(_ulong)ptr+size);

	if(boost::icl::contains(mem,r)) {
		return true;
	}

	if(!(boost::icl::intersects(mem,r))) {
		copyInterval(r,st);
		return true;
	}

	boost::icl::interval_set<_ulong, std::less, right_open_interval<_ulong> > list = findIntervals(r);

	for(interval_set<_ulong, std::less, right_open_interval<_ulong> >::iterator memloc = list.begin(); memloc != list.end(); ++memloc) {
			copyInterval(*memloc,st);
	}

	return true;
}

void DeviceCache::cacheReset() {
	mem.clear();
}

bool DeviceCache::copyInterval(right_open_interval<_ulong> r, cudaStream_t* st) {


	void *ptrFrom = (void*) r.lower();
	void *ptrTo = (void*) ((unsigned long long) cache + (r.lower() & offset_filter));

//	printf("Copying\n");
	_ulong size = r.upper() - r.lower();

	checkCudaErrors(cudaMemcpyAsync(ptrTo, // dst
					ptrFrom,// src
					size,// size
					cudaMemcpyHostToDevice, *st// stream
					));
//	boost::mutex::scoped_lock lock(_lock);
	mem.add(r);
	return true;
}

void DeviceCache::printCache() {
	cout << mem << endl;
}

boost::icl::interval_set<_ulong, std::less, right_open_interval<_ulong> > DeviceCache::findIntervals(boost::icl::right_open_interval<_ulong> r) {
//	boost::mutex::scoped_lock lock(_lock);

	boost::icl::interval_set<_ulong, std::less, right_open_interval<_ulong> > toCache;
	right_open_interval<_ulong> elem = r;

	for(interval_set<_ulong, std::less, right_open_interval<_ulong> >::iterator memloc = mem.begin(); memloc != mem.end() && !is_empty(elem); ++memloc) {
		right_open_interval<_ulong> elem2 = right_subtract(elem, *memloc);
		elem = left_subtract(elem, *memloc);
		if(!is_empty(elem2) && elem2 != elem) {
			toCache.add(elem2);
		}
	}

	if(!is_empty(elem)) {
		toCache.add(elem);
	}
	return toCache;
}
