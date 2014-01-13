/*
 * SpinLock.h
 *
 *  Created on: May 12, 2011
 *      Author: jbarbosa
 */

#ifndef SPINLOCK_H_
#define SPINLOCK_H_

#include <helper_cuda.h>
#include <helper_math.h>
#include <config/common.h>
#include <gamalib/mutex/atomics.h>
#include<gamalib/utils/x86_utils.h>

struct SpinLock {

#ifndef __CUDACC__
	atomic<CPU_X86,int> mutex;
#else
	atomic<GPU_CUDA,int> mutex;
#endif


	__DEVICE__  SpinLock() { mutex.exchange(-1); };

	__DEVICE__ __forceinline ~SpinLock() {};

	__DEVICE__ __forceinline bool Try() {
		return mutex.boolCAS(-1,1);
	}

	__DEVICE__ __forceinline bool Acquire(int id) {
		while(!Try());
		return true;
	}

	__DEVICE__ __forceinline bool Release(int id) {
		mutex.exchange(-1);
		return true;

	}
};

#endif /* SPINLOCK_H_ */
