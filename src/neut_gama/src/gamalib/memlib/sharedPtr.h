/*
 * smartpointer.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef SHAREDPTR_H_
#define SHAREDPTR_H_

#include <gamalib/memlib/LowLevelMemAllocator.h>
#include <gamalib/memlib/MemorySystem.h>
#include <gamalib/cache/cache.h>

class sharedPtr {

public:
	__DEVICE__
	void * operator new(size_t size) {
		return LowLevelMemAllocator::sharedMemory(size);
	}
	__DEVICE__
	void operator delete(void * mem) {

		if (mem)
			LowLevelMemAllocator::freeShared(mem);
	}
	__DEVICE__
	void * operator new[](size_t size) {
		return LowLevelMemAllocator::sharedMemory(size);
	}
	__DEVICE__
	void operator delete[](void * mem) {
		if (mem)
			LowLevelMemAllocator::freeShared(mem);
	}

};

#endif /* SHAREDPTR_H_ */
