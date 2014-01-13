/*
 * DeviceX86Conf.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef DEVICEX86CONF_H_
#define DEVICEX86CONF_H_


#include <config/workqueue.cfg.h>

#include "Device.h"

class DeviceX86: public Device {




public:
	DeviceX86(unsigned int, MemorySystem*, Scheduler*, boost::barrier*);
	virtual ~DeviceX86();
	virtual bool submit(work* w);
	void* runMaster();
	void* runWorker();

	static void* threadMaster(void*);
	static void* threadWorker(void*);

};

#endif /* DEVICEX86CONF_H_ */
