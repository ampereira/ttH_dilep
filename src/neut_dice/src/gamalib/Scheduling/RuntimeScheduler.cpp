/*
 * RuntimeScheduler.cpp
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#include <gamalib/gamalib.h>
#include <gamalib/gamasys.h>

//#include "RuntimeScheduler.h"

//static inline int log2(long x) {
//  long y;
//  asm ( "\tbsr %1, %0\n"
//      : "=r"(y)
//      : "r" (x)
//  );
//  return y;
//}

RuntimeScheduler::RuntimeScheduler() :
		npart(0), SyncBarrier(TOTAL_DEVICES + 1) {

	_gmem = new MemorySystem();
	LowLevelMemAllocator::_memSys = (MemorySystem*) _gmem;

#if defined(STATIC)
	ds = new StaticScheduler();
#endif
#if defined(DEMAND_DRIVEN)
	ds = new DemandScheduler();
#endif
	unsigned int GPU_ID = 0;

	for (unsigned dev = 0; dev < TOTAL_DEVICES; dev++) {

		npart += TOTAL_CORES_TYPES[dev];

		switch (DEVICE_TYPES[dev]) {
		case CPU_X86:
			SysDevices[dev] = new DeviceX86(dev, (MemorySystem*) _gmem, ds,
					&SyncBarrier);
			ds->setQueueDevice(dev, SysDevices[dev]->INBOX);
			break;
		case GPU_CUDA:
			SysDevices[dev] = new DeviceCuda(dev, GPU_ID++,
					(MemorySystem*) _gmem, ds, &SyncBarrier);
			ds->setQueueDevice(dev, SysDevices[dev]->INBOX);
			break;
		default:
			SysDevices[dev] = NULL;
			break;
		}
	}

	npart = roundUpToNextPowerOfTwo(npart);

	SyncBarrier.wait();
	synchronize();
}

RuntimeScheduler::~RuntimeScheduler() {

	for (unsigned dev = 0; dev < TOTAL_DEVICES; dev++) {
		SysDevices[dev]->sendSignal(TERMINATE_SIGNAL);
	}

	X86MemFence();

	for (unsigned dev = 0; dev < TOTAL_DEVICES; dev++) {
		SysDevices[dev]->join();
	}

	delete ds;
}

void RuntimeScheduler::synchronize() {

	for (unsigned dev = 0; dev < TOTAL_DEVICES; dev++) {
		SysDevices[dev]->sendSignal(SYNC_SIGNAL);
	}

	SyncBarrier.wait();

	ds->normalize(ds->execPayload);


}

bool RuntimeScheduler::submit(work* w) {
	double start = getTimeMS();
	ds->execPayload = true;
	if(TOTAL_DEVICES == 1) {
		ds->push(0, w);
		return true;
	}

	if (IS_DICEABLE(w->WORK_TYPE_ID)) {
		double* m = ds->getModel(w->getWorkTypeID());
		unsigned int part = TOTAL_DEVICES;

		ptrwork* l = w->dice(m, part);
		if (l == NULL) {
			int devSel = 0;
			int max = m[0];
			for (int dev = 1; dev < TOTAL_DEVICES; dev++) {
				if (max <= m[dev]) {
					max = m[dev];
					devSel = dev;
				}
			}
			ds->push(devSel, w);

		} else {

			for (int dev = 0; dev < TOTAL_DEVICES; dev++) {
				if (l[dev] != NULL) {
					l[dev]->start = start;
					SysDevices[dev]->submit(l[dev]);
//					SysDevices[dev]->wake.notify_all();
				}
			}

			delete l;
		}
		delete m;
	} else {
		unsigned dev = rand() % TOTAL_DEVICES;
		ds->push(dev, w);
//		SysDevices[dev]->wake.notify_all();
	}
	return true;
}
