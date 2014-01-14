/*
 * mutex.h
 *
 *  Created on: Mar 10, 2011
 *      Author: jbarbosa
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include "core.h"


struct __align__(16) SpinLock {
public:

	volatile int mutex;

public:
	__HYBRID__ __forceinline SpinLock()	{
		mutex = -1;
	}

	__HYBRID__ __forceinline  virtual ~SpinLock() {
	}

//	__HYBRID__ __forceinline
//	virtual void Release() {
//		mutex = -1;
//	}

	__HYBRID__ __forceinline bool Release() {
		int a = blockIdx.x * blockDim.x;

				atomicCAS((int*)&mutex,a,-1);
				return true;
		}


	__HYBRID__
	bool Try() {
		int a = blockIdx.x * blockDim.x;
		atomicCAS((int*) &mutex, -1, a);
			return (mutex == a);
	}

	__HYBRID__
	void Acquire() {
		while (!Try());
	}

};


class SpinLock2 {
public:

	volatile int mutex;

public:
	__HYBRID__  SpinLock2() { mutex=-1; };
	__HYBRID__ __forceinline ~SpinLock2() {};

	__HYBRID__ __forceinline bool Try(int id) {
			atomicCAS((int*)&mutex,-1,id);
			return (mutex == id);
	}

	__HYBRID__ __forceinline bool Acquire(int id) {while(!Try(id)); return true;}

	__HYBRID__ __forceinline bool Release(int id) {
			atomicCAS((int*)&mutex,id,-1);
			return true;
	}
};

class SpinLockWarp {
public:

	volatile int mutex;

public:
	__HYBRID__ __forceinline SpinLockWarp()	{
		mutex = -1;
	}

	__HYBRID__ __forceinline  virtual ~SpinLockWarp() {
	}

	__HYBRID__ __forceinline
	virtual void Release() {
		mutex = -1;
	}


	__HYBRID__
	bool Try() {
		int v = threadIdx.x >> 5;
		//printf("%d\n",v);
			atomicCAS((int*) &mutex, -1,v);
			return (mutex == v);
	}

	__HYBRID__
	void Acquire() {
		while (!Try())
			;
	}

};


#endif /* MUTEX_H_ */
