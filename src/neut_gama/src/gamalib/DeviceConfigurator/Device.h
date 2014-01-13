/*
 * DeviceConfig.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef DEVICECONFIG_H_
#define DEVICECONFIG_H_

#include <boost/thread/thread.hpp>
#include <boost/lockfree/queue.hpp>

#include <config/workqueue.cfg.h>

#include <gamalib/utils/x86_utils.h>
#include <gamalib/memlib/smartpointer.h>
#include <gamalib/work/work.h>
#include <gamalib/workqueues/Workqueue.h>
#include <gamalib/Communication/channel.h>
#include <gamalib/Scheduling/DemandScheduler.h>

#include <boost/thread/mutex.hpp>
#include <boost/thread/barrier.hpp>


class Device {
public:

//	boost::mutex mut;
//	boost::condition_variable wake;

	double avg;
	double lastSync;
	unsigned int deviceId;
	DEVICE_TYPE Type;
	unsigned int numberOfCores;
	ComChannel channel;
	boost::barrier *SyncBarrier;

	boost::thread master;
	boost::thread_group workers;
	Scheduler *ds;
	boost::lockfree::queue< work*>* INBOX;
	boost::lockfree::queue< work*>* OUTBOX;

	MemorySystem* _memSys;

	boost::atomic<int> WorkerCounter;
	boost::atomic<int> ActiveWorkers;
	boost::atomic<int> IdleWorkers;



public:
	Device(unsigned int device, DEVICE_TYPE T, MemorySystem* memSys, Scheduler *s, boost::barrier *SB) : deviceId(device), Type(T), _memSys(memSys), ds(s), SyncBarrier(SB), avg(0) {
		WorkerCounter = 0;
		ActiveWorkers = 0;
		IdleWorkers = 0;
		INBOX = new boost::lockfree::queue< work*>(INBOX_QUEUE_SIZE);
		OUTBOX = new boost::lockfree::queue< work*>(INBOX_QUEUE_SIZE);
		lastSync = getTimeMS();
	}

	virtual ~Device() {};

	virtual bool submit(work* witem);

	__forceinline void sendSignal(SIGNAL_DEVICE _signal) {
		channel.toDevice = _signal;
	}

	virtual bool wait() {
		while(ds->allEmpty()){
		}
		return true;
	}

	void sync();

	bool __inline__ join()
	{
		master.join();
		return true;
	}
protected:

	Device(const Device&);                // no implementation
	Device& operator=(const Device&);    // no implementation
};

#endif /* DEVICECONFIG_H_ */
