/*
 * smartpointer.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include <gamalib/memlib/LowLevelMemAllocator.h>
#include <gamalib/memlib/MemorySystem.h>
#include <gamalib/cache/cache.h>


template<typename T>
class smartPtr {

public:
	T* ptr;
	T* ptrCache;

public:

	__HYBRID__ __forceinline
	smartPtr() : ptr(NULL), ptrCache(NULL) {

	}
	__HYBRID__ __forceinline
	smartPtr(smartPtr<T>& rhs) {
			ptr = rhs.ptr;
			ptrCache = rhs.ptrCache;
	}

	__HYBRID__ __forceinline
	smartPtr(const smartPtr<T>& rhs) {
		ptr = rhs.ptr;
		ptrCache = rhs.ptrCache;
	}

	__HYBRID__ __forceinline
	smartPtr(T* ptr) {
		this->ptr = ptr;
		ptrCache = ptr;
	}

	__DEVICE__ __forceinline
	smartPtr(T ptr) {
		alloc(sizeof(T));
		*(this->ptr) = ptr;
		ptrCache = ptr;
	}

	__DEVICE__ __forceinline
	smartPtr(size_t size) {
		alloc(size);
		ptrCache = ptr;
	}

	template< typename NewTypeT > __forceinline
	smartPtr( smartPtr< NewTypeT > &rhs )
	{
		ptr = (T*)rhs.ptr;
		ptr = (T*)rhs.ptrCache;
	}

	__DEVICE__ __forceinline
	void operator()(size_t size){
		alloc(size);
	}

	__HYBRID__ __forceinline
	~smartPtr() {
	}

	__DEVICE__ __forceinline
	void release() {
		ptr->T::~T();
		dealloc();
	}

	__HYBRID__ __forceinline
	T&	operator* () {
		return *ptr;
	}
	__HYBRID__ __forceinline
	T* operator->() {
		return ((T*)ptr);
	}

//	__DEVICE__ __forceinline
//	T& operator[] (unsigned int i) {
//		return *(T*)(translateAddr(getPtr(i)));
//	}

	__DEVICE__ __forceinline
	void cacheIt() {
		ptrCache = (T*)translateAddr(ptr);
	}
	__DEVICE__ __forceinline
	T* cache() {
		ptrCache = (T*)translateAddr(ptr);
		return ptrCache;
	}

	__DEVICE__ __forceinline
	T& operator[] (unsigned int i) {
#ifdef __CUDACC__
		return ptrCache[i];
#else
		return ptr[i];
#endif

	}


	__HYBRID__ __forceinline
	T* getPtr() {
		return ((T*)ptr);
	}

	__HYBRID__ __forceinline
	T* getPtr(unsigned i) {
		return (T*)&ptr[i];
	}

	__DEVICE__ __forceinline
	T get(unsigned i){
		return ptrCache[i];
	}

	__DEVICE__ __forceinline
	void set(unsigned i, T value){
		ptr[i]=value;
	}


private:

	__DEVICE__ __forceinline
	void alloc(size_t size) {
		this->ptr = (T*)LowLevelMemAllocator::sharedMemory(size);
	}

	__DEVICE__ __forceinline
	void dealloc() {
		LowLevelMemAllocator::freeShared(ptr);
	}

};

#endif /* SMARTPOINTER_H_ */
