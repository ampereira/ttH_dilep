/*
 * contant.cuda.cu
 *
 *  Created on: Sep 16, 2012
 *      Author: jbarbosa
 */
#include <config/common.h>

__device__ __constant__ void* _dcache;
__device__ __constant__ unsigned int DeviceID_GPU;
__device__ __constant__ void* _memGPU;
__device__ __constant__ void* _cache;
__device__ __constant__ unsigned long* _pages;
__device__ __constant__ unsigned long* _pagesLock;
__device__ __constant__ unsigned long* _pagesCount;


__constant__ int nnodesd, nbodiesd;
__constant__ float dtimed, dthfd, epssqd, itolsqd;
__constant__ volatile float *massd, *posxd, *posyd, *poszd, *velxd, *velyd, *velzd, *accxd, *accyd, *acczd;
__constant__ volatile float *maxxd, *maxyd, *maxzd, *minxd, *minyd, *minzd;
__constant__ volatile int *errd, *sortd, *childd, *countd, *startd;
__constant__ int *count_iterations;
__device__ volatile int stepd, bottomd, maxdepthd, blkcntd;
__device__ volatile float radiusd;


void* dcache = NULL;
