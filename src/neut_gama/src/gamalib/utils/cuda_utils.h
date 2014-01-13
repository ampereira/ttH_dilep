/*
 * cuda_utils.h
 *
 *  Created on: Apr 13, 2012
 *      Author: rr
 */

#ifndef CUDA_UTILS_H_
#define CUDA_UTILS_H_

#include "cuda.h"
#include "cuda_runtime.h"

void inline checkCUDAmemory(char* t = NULL) {

	//cudaDeviceSynchronize();
	size_t free, total;
	cuMemGetInfo(&free, &total);
	fprintf(stderr, "%s mem %ld total %ld\n", t, free / 1024 / 1024, total / 1024 / 1024);

}

void inline checkCUDAError(char* t = NULL) {
#ifdef __DEBUG

	cudaError_t err = cudaGetLastError();
	if (cudaSuccess != err) {
		checkCUDAmemory("error");
		fprintf(stderr, "Cuda error %s: %s.\n", t, cudaGetErrorString(err));
		exit(-1);
	}
#endif
}

void inline __E(cudaError_t err) {
	if (cudaSuccess != err) {
		checkCUDAmemory("error");
		fprintf(stderr, "CUDA Runtime API error: %s.\n", cudaGetErrorString(err));
		exit(-1);
	}
}



#endif /* CUDA_UTILS_H_ */
