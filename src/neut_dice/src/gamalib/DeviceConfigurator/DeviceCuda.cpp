/*
 * DeviceCudaConf.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: jbarbosa
 */

#include <vector>

#include <config/common.h>
#include <pthread.h>
#include <stdio.h>

#include <helper_cuda.h>

#include <gamalib/utils/x86_utils.h>

#include <config/vtable.h>

#include <vector>
#include <algorithm>

#include "DeviceCuda.h"

#include <boost/thread.hpp>
#include <boost/thread/barrier.hpp>

extern void initCudaDevice(unsigned int DeviceID, MemorySystem* mem);

struct devpair {
	unsigned int id;
	unsigned int c;

	devpair(unsigned int device_id, unsigned int cap) :
			id(device_id), c(cap) {
	}
};

bool descend(devpair i, devpair j) {
	return (i.c > j.c);
}

inline unsigned GetMaxGflopsDeviceId(int current_id) {
	int current_device = 0, sm_per_multiproc = 0;
	int device_count = 0, best_SM_arch = 0;
	cudaDeviceProp deviceProp;
	cudaGetDeviceCount(&device_count);

	// Find the best major SM Architecture GPU device
	while (current_device < device_count) {
		cudaGetDeviceProperties(&deviceProp, current_device);

		// If this GPU is not running on Compute Mode prohibited, then we can add it to the list
		if (deviceProp.computeMode != cudaComputeModeProhibited) {
			if (deviceProp.major > 0 && deviceProp.major < 9999) {
				best_SM_arch = MAX(best_SM_arch, deviceProp.major);
			}
		}

		current_device++;
	}

	std::vector<devpair> devs;
	current_device = 0;
	for (int current_device = 0; current_device < device_count;
			current_device++) {
		cudaGetDeviceProperties(&deviceProp, current_device);

		// If this GPU is not running on Compute Mode prohibited, then we can add it to the list
		if (deviceProp.computeMode != cudaComputeModeProhibited) {
			if (deviceProp.major == 9999 && deviceProp.minor == 9999) {
				sm_per_multiproc = 1;
			} else {
				sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major,
						deviceProp.minor);
			}
			unsigned int tM = deviceProp.totalGlobalMem / (1024 * 1024)
					* deviceProp.memoryClockRate * 2;
			devs.push_back(
					devpair(current_device,
							(sm_per_multiproc * deviceProp.multiProcessorCount
									* deviceProp.clockRate / 1.e9)
									+ tM / 1.e9));
		}
	}

	sort(devs.begin(), devs.end(), descend);
	return devs.at(current_id).id;
}

DeviceCuda::DeviceCuda(unsigned int deviceID, unsigned int _cudaDeviceID,
		MemorySystem* memSys, Scheduler* s, boost::barrier *SB) :
		Device(deviceID, GPU_CUDA, memSys, s, SB), cudaDeviceID(_cudaDeviceID) {
	int deviceCount = DeviceCuda::cudaDevices();
	if (deviceCount == 0 || (unsigned) deviceCount <= cudaDeviceID) {
		fprintf(stderr, "There is no %u device supporting CUDA.\n",
				cudaDeviceID);
		exit(0);
	}

	cudaDeviceID = GetMaxGflopsDeviceId(cudaDeviceID);

	checkCudaErrors(cudaSetDevice(cudaDeviceID));
	checkCudaErrors(cudaGetDeviceProperties(&cdp, cudaDeviceID));
	numberOfCores = cdp.multiProcessorCount;
	unsigned wide = _ConvertSMVer2Cores(cdp.major, cdp.minor);
	checkCudaErrors(cudaDeviceSetCacheConfig(cudaFuncCachePreferL1));

	fprintf(stderr, "aa Device %s CORES: %u WS: %u BK: %u\n", cdp.name,
			numberOfCores, cdp.warpSize, wide);

	for (int st = 0; st < 32; st++)
		checkCudaErrors(cudaStreamCreate(&(streams[st])));

	initCudaDevice(deviceID, LowLevelMemAllocator::_memSys);

#if defined GAMA_CACHE
	cache = new DeviceCache();
	checkCudaErrors(cudaDeviceSynchronize());
#endif
	master = boost::thread(DeviceCuda::threadMaster, this);
	master.detach();


	fprintf(stderr, "Finished Device %d init\n", deviceId);
}

DeviceCuda::~DeviceCuda() {

	for (int st = 0; st < 32; st++)
		checkCudaErrors(cudaStreamDestroy(streams[st]));
}

bool DeviceCuda::submit(work* w) {

	unsigned int part;

	if (IS_REGULAR(w->WORK_TYPE_ID) || !IS_DICEABLE(w->WORK_TYPE_ID)) {
		//part = TOTAL_CORES_TYPES[deviceId];
		//INBOX->push(w);
		ds->push(deviceId,w);
//		wake.notify_all();
		return true;
	}
	part = TOTAL_CORES_TYPES[deviceId] << DICE_SIZE;

	double* p = new double[part];
	for (int i = 0; i < part; i++) {
		p[i] = 1.f / (float) part;
	}

	ptrwork* l = w->dice(p, part);
	if (l == NULL) {
		//INBOX->push(w);
		ds->push(deviceId,w);
	} else {
		for (unsigned jj = 0; jj < part; jj++) {
			if (l[jj] != NULL) {
				l[jj]->start = w->start;
				ds->push(deviceId,l[jj]);
			}
		}
//		delete w;
		delete l;
	}
	delete p;
//	wake.notify_all();
	return true;
}

void* DeviceCuda::runMaster(void) {

	cudaSetDevice(cudaDeviceID);
	DeviceID_CPU = deviceId;
	_memCPU = _memSys;

	sync();

	for (unsigned _worker = 0; _worker < TOTAL_CORES_TYPES[deviceId];
			_worker++) {
		boost::thread t = boost::thread(DeviceCuda::threadWorker, this);
		t.detach();
		workers.add_thread(&t);
	}

	lastSync = getTimeMS();
	unsigned long long request = 8;
	unsigned int st = WorkerCounter++ & 31;
	work* w_item;
	while (channel.toDevice != TERMINATE_SIGNAL || !ds->allEmpty()) {

		if (INBOX->empty() && !ds->allEmpty()) {
			request = ds->request(deviceId, request);
		}

//		if (!INBOX->empty() && IdleWorkers != 0) {
//			wake.notify_all();
//		}

		if (channel.toDevice == SYNC_SIGNAL
				&& ds->allEmpty()
				&& IdleWorkers == TOTAL_CORES_TYPES[deviceId]
				) {
//			printf("Device %u sync\n",deviceId);
#if defined GAMA_CACHE
			cache->cacheReset();
#endif
			channel.toDevice = NULL_SIGNAL;
			sync();
			channel.fromDevice = DEVICE_KERNEL_RUNNING;
			request = 8;
//			printf("Device %u exited sync\n",deviceId);
		}
	}

	//workers.join_all();
}

void* DeviceCuda::runWorker(void) {
	DeviceID_CPU = deviceId;
	_memCPU = _memSys;
	cudaSetDevice(cudaDeviceID);
	unsigned int st = WorkerCounter++ & 31;
	work* w_item;
	while (channel.toDevice != TERMINATE_SIGNAL || !ds->allEmpty()) {

		if (ds->allEmpty()) {
			IdleWorkers++;
			wait();
			IdleWorkers--;
		}
		w_item = NULL;
		if (ds->pop(deviceId,w_item) && w_item != NULL) {
			float ptime;
			cudaEvent_t event, events;
			cudaEventCreate(&event);
			cudaEventCreate(&events);
			cudaEventRecord(events, streams[st]);
			double start = getTimeMS();
			classWideKernel(w_item, st);
			cudaEventRecord(event, streams[st]);
			cudaEventSynchronize(event);
			cudaEventElapsedTime(&ptime, events, event);
			double end = getTimeMS();
			ptime = end - start;
			cudaEventDestroy(event);
			cudaEventDestroy(events);
			double awork = w_item->estimateWork();
			ds->executed(deviceId, w_item->getWorkTypeID(), awork, ptime);
		}
	}
}

void* DeviceCuda::threadMaster(void* a_param) {
	DeviceCuda* master = static_cast<DeviceCuda*>(a_param);
	return master->runMaster();
}

void* DeviceCuda::threadWorker(void* a_param) {
	DeviceCuda* worker = static_cast<DeviceCuda*>(a_param);
	return worker->runWorker();
}
