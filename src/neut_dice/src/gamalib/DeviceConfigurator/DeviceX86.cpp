/*
 * DeviceX86Conf.cpp
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */
#include <config/common.h>

#include <pthread.h>
#include <stdio.h>
#include <omp.h>
#include <config/vtable.h>
#include <vector>
#include <algorithm>

#include <gamalib/utils/x86_utils.h>

#include <boost/thread.hpp>
#include <boost/thread/barrier.hpp>

#include "Device.h"
#include "DeviceX86.h"

__thread unsigned int DeviceID_CPU;
__thread void* _memCPU;

DeviceX86::DeviceX86(unsigned int deviceID, MemorySystem* memSys, Scheduler* s,
		boost::barrier *SB) :
		Device(deviceID, CPU_X86, memSys, s, SB) {


	fprintf(stderr, "Device %s CORES: %u W: %u\n", "X86", TOTAL_CORES_TYPES[deviceId],TOTAL_CORES_TYPES[deviceId]);

	master = boost::thread(DeviceX86::threadMaster, this);
	master.detach();


	fprintf(stderr, "Finished Device %d init\n", deviceId);
}

DeviceX86::~DeviceX86() {

}

bool DeviceX86::submit(work* w) {
	unsigned int part;

	if (!IS_DICEABLE(w->WORK_TYPE_ID)) {
		//INBOX->push(w);
		ds->push(deviceId,w);
//		wake.notify_all();
		return true;
	}

	part = TOTAL_CORES_TYPES[deviceId] << (DICE_SIZE+1);

	double* p = new double[part];
	for (int i = 0; i < part; i++) {
		p[i] = 1.f / (float) part;
	}

	ptrwork* l = w->dice(p, part);
	if (l == NULL) {
		//INBOX->push(w);
		ds->push(deviceId,w);
	} else {
		for (unsigned jj = 0; jj < part; jj++) {
			if (l[jj] != NULL) {
				l[jj]->start = w->start;
				//INBOX->push(l[jj]);
				ds->push(deviceId,l[jj]);
			}
		}
//		delete w;
		delete l;
	}
	delete p;
//	wake.notify_all();
	return true;

}

void* DeviceX86::runMaster(void) {

	DeviceID_CPU = deviceId;
	double start, end;

	_memCPU = _memSys;


	sync();
	for (unsigned _worker = 0; _worker < TOTAL_CORES_TYPES[deviceId];
			_worker++) {
		boost::thread t = boost::thread(DeviceX86::threadWorker, this);
		t.detach();
		workers.add_thread(&t);
	}

	lastSync = getTimeMS();
	unsigned long long request = 8;

	while (channel.toDevice != TERMINATE_SIGNAL || !ds->allEmpty()) {

		if (INBOX->empty() && ds->allEmpty()) {
			request = ds->request(deviceId, request);
		}

		if (channel.toDevice == SYNC_SIGNAL
				&& ds->allEmpty()
				&& IdleWorkers == TOTAL_CORES_TYPES[deviceId]
				) {
//			printf("Device %u sync\n",deviceId);
			channel.toDevice = NULL_SIGNAL;
			sync();
			channel.fromDevice = DEVICE_KERNEL_RUNNING;
			request = 8; // * ds->assignChunk(deviceId);
			//wake.notify_all();
//			printf("Device %u exited sync\n",deviceId);
		}
	}

	//workers.join_all();
}

void* DeviceX86::runWorker(void) {
	DeviceID_CPU = deviceId;
	_memCPU = _memSys;
	unsigned int st = WorkerCounter++ & 31;
	work* w_item;
	while (channel.toDevice != TERMINATE_SIGNAL || !ds->allEmpty()) {
		X86MemFence();
		if (ds->allEmpty()) {
			IdleWorkers++;
			wait();
			IdleWorkers--;
		}
		w_item = NULL;
//		ActiveWorkers++;
		if (ds->pop(deviceId,w_item) && w_item != NULL) {
			double start = getTimeMS();

			(w_item->*WORK_CPU_TABLE[w_item->getWorkTypeID()])();
			if (w_item->estimateWork() != 0) {
				double ptime = (getTimeMS() - start);
				double awork = w_item->estimateWork();
				ds->executed(deviceId, w_item->getWorkTypeID(), awork, ptime);
			}
//			delete w_item;
		}
//		ActiveWorkers--;
	}
}

void* DeviceX86::threadMaster(void* a_param) {
	DeviceX86* master = static_cast<DeviceX86*>(a_param);
	return master->runMaster();
}

void* DeviceX86::threadWorker(void* a_param) {
	DeviceX86* worker = static_cast<DeviceX86*>(a_param);
	return worker->runWorker();
}

