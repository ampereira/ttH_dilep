/*
 * system.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

enum DEVICE_TYPE {
	CPU_X86 = 0,	// X86 compatible
	GPU_CUDA,	// GPU_CUDA
	GPU_LIB,
	HYBRID,
	SCHEDULER,
	LOG
};

enum MEM_TYPE {
	HOST = 0,
	SHARED,
	DEVICE
};

#ifndef SCONF
#define SCONF 4
#endif

#ifndef X86C
#define X86C 12
#endif

#ifndef GPUC
#define GPUC 2
#endif


const unsigned long NTHREAD = 256;

#if (SCONF==0)
const unsigned TOTAL_DEVICES = 1;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {GPU_CUDA};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {GPUC};
const float LOADS[TOTAL_DEVICES] = {1.f};
#endif

#if (SCONF==1)
const unsigned TOTAL_DEVICES = 2;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {GPU_CUDA,GPU_CUDA};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {GPUC,GPUC};
const float LOADS[TOTAL_DEVICES] = {.5f,.5f};
#endif
#if (SCONF==2)
const unsigned TOTAL_DEVICES = 2;
const float P = 1.f / (float) TOTAL_DEVICES;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {GPU_CUDA,CPU_X86};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {GPUC,X86C};
const float LOADS[TOTAL_DEVICES] = {0.80f,0.20f};
#endif
#if (SCONF==3)
const unsigned TOTAL_DEVICES = 2;
const float P = 1.f / (float) TOTAL_DEVICES;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {GPU_CUDA,CPU_X86};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {GPUC,2*X86C-GPUC};
const float LOADS[TOTAL_DEVICES] = {.80f,.20f};
#endif
#if (SCONF==4)
const unsigned TOTAL_DEVICES = 3;
const float P = 1.f / (float) TOTAL_DEVICES;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {GPU_CUDA,GPU_CUDA,CPU_X86};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {GPUC,GPUC, X86C};
const float LOADS[TOTAL_DEVICES] = {1.f/3.f,1.f/3.f,1.f/3.f};
#endif
#if (SCONF==5)
const unsigned TOTAL_DEVICES = 3;
const float P = 1.f / (float) TOTAL_DEVICES;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {GPU_CUDA,GPU_CUDA,CPU_X86};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {GPUC,GPUC, X86C-GPUC-GPUC};
const float LOADS[TOTAL_DEVICES] = {1.f/3.f,1.f/3.f,1.f/3.f};
#endif
#if (SCONF==6)
const unsigned TOTAL_DEVICES = 1;
const float P = 1.f / (float) TOTAL_DEVICES;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {CPU_X86};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {X86C};
const float LOADS[TOTAL_DEVICES] = {1.f};
#endif
#if (SCONF==7)
const unsigned TOTAL_DEVICES = 1;
const float P = 1.f / (float) TOTAL_DEVICES;
const DEVICE_TYPE DEVICE_TYPES[TOTAL_DEVICES] = {CPU_X86};
const unsigned TOTAL_CORES_TYPES[TOTAL_DEVICES] = {2*X86C};
const float LOADS[TOTAL_DEVICES] = {1.f};
#endif


#endif /* SYSTEM_H_ */
