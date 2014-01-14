/*
 * cuda_utils.h
 *
 *  Created on: Apr 2, 2012
 *      Author: jbarbosa
 */

#ifndef CUDA_UTILS_H_
#define CUDA_UTILS_H_

#ifdef __CUDACC__

__inline__ __device__ unsigned int get_smid(void) {
	unsigned int ret = 0;
	asm("mov.u32 %0, %smid;" : "=r"(ret) );
	return ret;
}

__inline__ __device__ unsigned int get_warpid(void) {
	unsigned int ret = 0;
	asm("mov.u32 %0, %warpid;" : "=r"(ret) );
	__threadfence();
	return ret;
}

template<typename T>
__inline__ __device__ void memcpy_SIMD(T* dst, T* src,const unsigned long long nElement ) {

    const unsigned int laneID = threadIdx.x & 31;  
	for(int ii=laneID; ii < (nElement / sizeof(T)); ii+= 32) {
		dst[ii] = src[ii];
	}
	return;
}
#else
template<typename T>
__inline__ void memcpy_SIMD(T* dst, T* src, const long unsigned int nElement ) {

		memcpy(dst,src,sizeof(T)*nElement);
}
#endif

#endif /* CUDA_UTILS_H_ */
