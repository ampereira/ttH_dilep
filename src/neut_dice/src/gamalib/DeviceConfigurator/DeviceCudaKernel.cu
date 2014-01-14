/*
 * DeviceCuda.cu
 *
 *  Created on: Apr 11, 2012
 *      Author: jbarbosa
 */

#include <cuda.h>

#include <config/common.h>

#include <gamalib/memlib/LowLevelMemAllocator.h>

#include "DeviceCuda.h"

#include <config/vtable.h>
#include <config/vtable.cuh>
#include <gamalib/utils/cuda_utils.cuh>
#include <gamalib/GenericKernels/KernelCuda.cuh>
#include <gamalib/utils/x86_utils.h>

#define PostWork(W) outbox->enqueue(W);

typedef unsigned char byte;

__global__
//__launch_bounds__(256, 5)
void genericKernel(
		Workqueue<work, INBOX_QUEUE_SIZE, GPU_CUDA>* INBOX) {

	unsigned long index = blockIdx.x * blockDim.x + threadIdx.x;
	work* w_item;

	if ((w_item = INBOX->data[index]) != NULL) {
		(w_item->*WORK_GPU_TABLE[w_item->getWorkTypeID()])();
	}

}
__global__
//__launch_bounds__(256, 5)
void genericWideKernel(work* w_item) {
	(w_item->*WORK_GPU_TABLE[w_item->getWorkTypeID()])();
}

__inline__ void CudaTest(char *msg) {
	cudaError_t e;

	if (cudaSuccess != (e = cudaGetLastError())) {
		fprintf(stderr, "%s: %d\n", msg, e);
		fprintf(stderr, "%s\n", cudaGetErrorString(e));
		exit(-1);
	}
}
void DeviceCuda::classWideKernel(work* witem, unsigned st) {
	cudaSetDevice(cudaDeviceID);

#if defined GAMA_CACHE
	std::vector<pointerInfo>* Lw = (witem->*TOCACHEW_CPU_TABLE[witem->getWorkTypeID()])();
	std::vector<pointerInfo>* Lr = (witem->*TOCACHER_CPU_TABLE[witem->getWorkTypeID()])();

	for(int i=0; i< Lr->size(); i++) {
		cache->cachePtr((*Lr)[i].ptr,(*Lr)[i].lenght,&streams[st]);
	}


#endif

	if (!IS_LIB_CALL(witem->WORK_TYPE_ID)) {
		genericWideKernel<<< cdp.multiProcessorCount * 5, 256, 0, streams[st]>>>(witem);
		CudaTest("Launching parallel wide kernel");

	} else {

		(witem->*WORK_GPU_LIB_TABLE[witem->getWorkTypeID()])();
	}

	CudaTest("Launching parallel wide kernel");

#if defined GAMA_CACHE

	delete Lw;
	delete Lr;
#endif
}
