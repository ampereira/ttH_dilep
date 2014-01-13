/*
 * DeviceCudaConf.h
 *
 *  Created on: Apr 2, 2012
 *      Author: jbarbosa
 */


#ifndef DEVICECUDACONF_H_
#define DEVICECUDACONF_H_

#include <cuda.h>
#include <helper_cuda.h>

#include <config/workqueue.cfg.h>

#include "Device.h"

#include <gamalib/cache/DeviceCache.h>

class DeviceCuda : public Device {

public:

	unsigned int cudaDeviceID;
	cudaStream_t streams[32];
	int kernels_off_flight;

	DeviceCache* cache;

	cudaDeviceProp cdp;




public:

	DeviceCuda(unsigned int,unsigned int, MemorySystem*, Scheduler*, boost::barrier*);

	virtual ~DeviceCuda();
	virtual bool submit(work* w);
	void* runMaster();
	void* runWorker();

	static void* threadMaster(void*);
	static void* threadWorker(void*);

	static unsigned int cudaDevices() {
		int deviceCount = 0;
		cudaGetDeviceCount(&deviceCount);
		return deviceCount;
	}

	void classWideKernel(work*, unsigned);

//	virtual bool submit(work* witem);

};
#endif /* DEVICECUDACONF_H_ */
