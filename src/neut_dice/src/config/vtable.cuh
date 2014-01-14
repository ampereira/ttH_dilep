#ifndef __VTABLE_CUDA_H_
#define __VTABLE_CUDA_H_

#include <gamalib/work/work.h>
#include <config/vtable.h>

__device__ __constant__ executeFN WORK_GPU_TABLE[WORK_TOTAL] = {
    &work::execute<GPU_CUDA>,
    (executeFN)&saxpy::execute<GPU_CUDA>,
};

// __device__ __constant__ executeFN WORK_GPU_TABLE[WORK_TOTAL] = {
//     &work::execute<GPU_CUDA>,
//     (executeFN)&saxpy::execute<GPU_CUDA>,
// };

// __device__ __constant__ executeFN WORK_GPU_TABLE[WORK_TOTAL] = {
//     &work::execute<GPU_CUDA>,
//     (executeFN)&gemm::execute<GPU_CUDA>,
// };

// __device__ constant__ diceFN DICE_GPU_TABLE[WORK_TOTAL] = {
//     &work::dice<GPU_CUDA>,
//     (diceFN)&gemm::dice<GPU_CUDA>
// };

// __constant__ executeFN WORK_GPU_TABLE[WORK_TOTAL] = {

// 		&work::execute<GPU_CUDA>,
		// (executeFN)&BHForce::execute<GPU_CUDA>
// };

#endif
