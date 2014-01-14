/*
 * atomics.h
 *
 *  Created on: Dec 6, 2012
 *      Author: jbarbosa
 */

#ifndef ATOMICS_T_H_
#define ATOMICS_T_H_

template<DEVICE_TYPE, typename T>
class atomic {
public:
	volatile T _value;

	atomic() {
	}
	atomic(T value) : _value(value) {
	}

	T valCAS(T prev, T next);
	T boolCAS(T prev, T next) ;

	T exchange(T value);
	template<typename T2> inline T2 cast(void);

	T add(T value);
	T sub(T value);
	T operator+(const T value);
	T operator-(const T value);
	T operator+=(const T value);
	T operator-=(const T value);
	T operator=(const T value);

	T& operator=(const T& value);
	T operator++(int);
	T operator--(int);
};

#ifndef __CUDACC__
template<typename T>
class atomic<CPU_X86,T> {
public:
	volatile T _value;

	atomic() {
	}
	atomic(T value) : _value(value) {
	}

	inline T valCAS(T prev, T next)  __attribute__((always_inline))  {
		return __sync_val_compare_and_swap(&_value,prev,next);
	}
	inline bool boolCAS(T prev, T next) __attribute__((always_inline))  {
		return (prev==__sync_val_compare_and_swap(&_value,prev,next));
	}

	inline T exchange(T value) __attribute__((always_inline))  {
		return (T)__sync_lock_test_and_set(&_value,value);
	}
	template<typename T2> inline T2 cast(void) {
		return static_cast<T2>(_value);
	}

	inline T add(T value) __attribute__((always_inline))  {
		return __sync_fetch_and_add(&_value,value);
	}
	inline T sub(T value)  __attribute__((always_inline))  {
		return __sync_fetch_and_sub(&_value,value);
	}
	inline T operator+(const T value) __attribute__((always_inline))  {
		add(value);
	}
	inline T operator-(const T value) __attribute__((always_inline))  {
		sub(value);
	}
	inline T operator+=(const T value) __attribute__((always_inline))  {
		add(value);
	}
	inline T operator-=(const T value) __attribute__((always_inline))  {
		sub(value);
	}
	inline T operator=(const T value) __attribute__((always_inline))  {
		exchange(value);
	}

	inline T& operator=(const T& value) __attribute__((always_inline))  {
		return exchange(value);
	}

	inline T operator++(int) __attribute__((always_inline)) {
		return add(1);
	}
	inline T operator--(int) __attribute__((always_inline)) {
		return sub(1);
	}
};


template<>
class atomic<CPU_X86,double> {
public:
	volatile unsigned long long _value;

	atomic() {
	}
	atomic(double value) : _value(value) {
	}

	inline double valCAS(double prev, double next)  __attribute__((always_inline))  {

		unsigned long long* p = reinterpret_cast<unsigned long long*>(&prev);
		unsigned long long* n = reinterpret_cast<unsigned long long*>(&next);
		unsigned long long  a = __sync_val_compare_and_swap(&_value,*p,*n);
		return *reinterpret_cast<volatile double*>(&_value);
	}

	inline bool boolCAS(double prev, double next) __attribute__((always_inline))  {
		unsigned long long* p = reinterpret_cast<unsigned long long*>(&prev);
		unsigned long long* n = reinterpret_cast<unsigned long long*>(&next);
		return __sync_bool_compare_and_swap(&_value,*p,*n);
	}

	inline double exchange(double value) __attribute__((always_inline))  {
			double prev = _value;
            _value=value;
            asm volatile("sfence" ::: "memory");
            return prev;
	}
	template<typename T2> inline T2 cast(void) {
		return static_cast<T2>(*reinterpret_cast<volatile double*>(&_value));
	}

	inline double add(double value) __attribute__((always_inline))  {
		double v = *reinterpret_cast<volatile double*>(&_value);
		double n = v + value;
		while(!boolCAS(v,n)) {
			asm volatile("sfence" ::: "memory");
			v = *reinterpret_cast<volatile double*>(&_value);
			n = v + value;
		}
		return v;
	}
	inline double sub(double value)  __attribute__((always_inline))  {
		double v = *reinterpret_cast<volatile double*>(&_value);
		double n = v - value;
		while(!boolCAS(v,n)) {
			v = *reinterpret_cast<volatile double*>(&_value);
			n = v - value;
		}
		return v;
	}
	inline double operator+(const double value) __attribute__((always_inline))  {
		add(value);
	}
	inline double operator-(const double value) __attribute__((always_inline))  {
		sub(value);
	}
	inline double operator+=(const double value) __attribute__((always_inline))  {
		add(value);
	}
	inline double operator-=(const double value) __attribute__((always_inline))  {
		sub(value);
	}
	inline double operator=(const double value) __attribute__((always_inline))  {
		exchange(value);
	}

//	inline double& operator=(const double& value) __attribute__((always_inline))  {
//		return exchange(value);
//	}

	inline double operator++(int) __attribute__((always_inline)) {
		return add(1.f);
	}
	inline double operator--(int) __attribute__((always_inline)) {
		return sub(1.f);
	}
};

#else
template<typename T>
class atomic<GPU_CUDA,T> {
public:
	T _value;

	atomic() {
	}
	atomic(T value) : _value(value) {
	}

	__device__ __inline__ T valCAS(T prev, T next)  {
		return atomicCAS(&_value,prev,next);
	}
	__device__ __inline__ T boolCAS(T prev, T next) {
		return __any(prev==atomicCAS(&_value,prev,next));
	}

	__device__ __inline__ T exchange(T value) {
			T prev = _value;
            _value=value;
            __threadfence_system();
            return prev;
	}
	template<typename T2> __device__ __inline__ T2 cast(void) {
		return (T2)(_value);
	}

	__device__ __inline__ T add(T value) {
		return atomicAdd(&_value,value);
	}
	__device__ __inline__ T sub(T value) {
		return atomicSub(&_value,value);
	}
	__device__ __inline__ T operator+(const T value) {
		add(value);
	}
	__device__ __inline__ T operator-(const T value) {
		sub(value);
	}

	__device__ __inline__ T operator+=(const T value) {
		add(value);
	}
	__device__ __inline__ T operator-=(const T value) {
		sub(value);
	}

	__device__ __inline__ T operator=(const T value) {
		exchange(value);
	}

	__device__ __inline__ T& operator=(const T& value) {
		return exchange(value);
	}

	__device__ __inline__ T operator++(int) {
		add(1);
	}
	__device__ __inline__ T operator--(int) {
		sub(1);
	}
};

#endif

#endif /* ATOMICS_T_H_ */
