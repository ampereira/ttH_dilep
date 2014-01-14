#include <config/common.h>

#include <pthread.h>
#include <stdio.h>
#include <omp.h>
#include <config/vtable.h>
#include <vector>
#include <algorithm>

#include <gamalib/utils/x86_utils.h>
#include "Device.h"

bool Device::submit(work* w) {
	//INBOX->push(w);
	ds->push(deviceId,w);
//	wake.notify_all();
	return true;
}

void Device::sync() {

	double start = getTimeMS();
	SyncBarrier->wait();
	double sync = getTimeMS();
	double elapse = (sync-lastSync);
	double idle = (sync - start);
	lastSync = sync;
	if(ds->execPayload) {
		ds->updateIdle(deviceId,elapse, idle);
	}
}
