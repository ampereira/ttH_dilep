/*
 * work.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef WORK_H_
#define WORK_H_


#include <config/common.h>
#include <gamalib/memlib/smartpointer.h>
#include <gamalib/Datastructures/List.h>
#include <vector>


struct pointerInfo{
	void* ptr;
	size_t lenght;
	pointerInfo() : ptr(NULL), lenght(0) {}
	pointerInfo(void* p, size_t l) : ptr(p), lenght(l) {}

};

class work;

typedef work* ptrwork;

class work {

public:

	double start;

	unsigned long WORK_TYPE_ID;

	__HYBRID__ work(WORK_TYPE W_T_ID) :  WORK_TYPE_ID(W_T_ID) {
	};

	__HYBRID__ work() :  WORK_TYPE_ID(WORK_NONE) {
	};


	__HYBRID__ ~work() {
	};

	__HYBRID__ __forceinline unsigned int getWorkTypeID() {
		return FILTER_WORK(WORK_TYPE_ID);
	}


	virtual ptrwork* dice(double* wl, unsigned int &partition_size) {

		ptrwork* L = new ptrwork[partition_size];

		for(int i=0; i < partition_size; i++)
			L[i] = new work();
		return L;
	}

	template<DEVICE_TYPE> __HYBRID__ void execute() {
	}


	std::vector<pointerInfo>* toCacheR() {
		return new std::vector<pointerInfo>(0);
	}

	std::vector<pointerInfo>* toCacheW() {
		return new std::vector<pointerInfo>(0);
	}

	virtual double estimateWork() {
		return 1.f;
	}

	__DEVICE__
	void *operator new(size_t s) {
		return ((MemorySystem*)_gmem)->allocate(s);
	}

	__DEVICE__
	void *operator new[](size_t s) {
		return ((MemorySystem*)_gmem)->allocate(s);
	}


	__DEVICE__
	void operator delete[](void *dp) {
		return ((MemorySystem*)_gmem)->deallocate(dp);
	}

	__DEVICE__
	void operator delete(void *dp) {
		return ((MemorySystem*)_gmem)->deallocate(dp);
	}

};



#endif /* WORK_H_ */
