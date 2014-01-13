/*
 * global.def.h
 *
 *  Created on: Sep 16, 2012
 *      Author: jbarbosa
 */

#ifndef GLOBAL_DEF_H_
#define GLOBAL_DEF_H_

#if defined(__CUDACC__)

extern __device__ __constant__ void* _dcache;
extern __device__ __constant__ unsigned int DeviceID_GPU;
extern __device__ __constant__ void* _memGPU;
extern __device__ __constant__ void* _cache;
extern __device__ __constant__ unsigned long* _pages;


extern __constant__ int nnodesd, nbodiesd;
extern __constant__ float dtimed, dthfd, epssqd, itolsqd;
extern __constant__ volatile float *massd, *posxd, *posyd, *poszd, *velxd, *velyd, *velzd, *accxd, *accyd, *acczd;
extern __constant__ volatile float *maxxd, *maxyd, *maxzd, *minxd, *minyd, *minzd;
extern __constant__ volatile int *errd, *sortd, *childd, *countd, *startd;
extern __constant__ int *count_iterations;
extern __device__ volatile int stepd, bottomd, maxdepthd, blkcntd;
extern __device__ volatile float radiusd;

#define DeviceID DeviceID_GPU
#define _gmem _memGPU

#else

extern __thread unsigned int DeviceID_CPU;
extern __thread void* _memCPU;
#define DeviceID DeviceID_CPU
#define _gmem _memCPU

extern __thread void* _cache;
extern __thread unsigned long* _pages;
extern __thread unsigned long* _pagesLock;
extern __thread unsigned long* _pagesCount;



#endif

extern void* dcache;

#endif /* GLOBAL_DEF_H_ */
