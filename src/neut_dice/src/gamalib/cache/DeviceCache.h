/*
 * DeviceCache.h
 *
 *  Created on: Apr 5, 2013
 *      Author: jbarbosa
 */

#ifndef DEVICECACHE_H_
#define DEVICECACHE_H_

#include <cuda.h>
#include <driver_types.h>
#include <helper_cuda.h>

#include <boost/icl/interval.hpp>
#include <boost/icl/interval_set.hpp>
#include <boost/icl/split_interval_set.hpp>
#include <boost/icl/closed_interval.hpp>
#include <boost/icl/right_open_interval.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>


typedef unsigned long long _ulong;

class DeviceCache {

	void* cache;
	boost::mutex _lock;
	boost::icl::interval_set<_ulong, std::less, boost::icl::right_open_interval<_ulong> > mem;

public:
	DeviceCache();
	virtual ~DeviceCache();


	bool cachePtr(void* ptr, size_t size, cudaStream_t* st);
	void uncachePtr(void* ptr, size_t size, cudaStream_t* st) {
	}

	void cacheReset();

	void printCache();

private:

	boost::icl::interval_set<_ulong, std::less, boost::icl::right_open_interval<_ulong> > findIntervals(boost::icl::right_open_interval<_ulong> r);

	bool copyInterval(boost::icl::right_open_interval<_ulong> r, cudaStream_t* st);

};

#endif /* DEVICECACHE_H_ */
