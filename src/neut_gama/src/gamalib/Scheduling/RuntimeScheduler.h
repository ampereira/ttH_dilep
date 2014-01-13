/*
 * RuntimeScheduler.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef RUNTIMESCHEDULER_H_
#define RUNTIMESCHEDULER_H_

#include <config/common.h>

#include <gamalib/DeviceConfigurator/Device.h>
//#include <gamalib/DeviceConfigurator/DeviceX86.h>
//#include <gamalib/DeviceConfigurator/DeviceCuda.h>

#include <boost/thread/barrier.hpp>
#include <gamalib/Scheduling/StaticScheduler.h>
#include <gamalib/Scheduling/DemandScheduler.h>


using namespace std;

class RuntimeScheduler {

	Device* SysDevices[TOTAL_DEVICES];

	unsigned long npart;

	boost::barrier SyncBarrier;
	pthread_cond_t NoWork;
	Scheduler *ds;


public:
	RuntimeScheduler();
	virtual ~RuntimeScheduler();

	bool submit(work* w);

	void synchronize();

};

#endif /* RUNTIMESCHEDULER_H_ */
