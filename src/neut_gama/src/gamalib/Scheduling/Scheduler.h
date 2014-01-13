/*
 * Scheduler.h
 *
 *  Created on: Dec 13, 2012
 *      Author: jbarbosa
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <config/common.h>
#include <config/vtable.h>

#include <boost/atomic.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

class Scheduler {
public:

	bool execPayload;
	boost::mutex ILOCK[TOTAL_DEVICES];
	boost::lockfree::queue<work*>* INBOX[TOTAL_DEVICES];
	boost::atomic<int> counter;

	Scheduler() :
			counter(0), execPayload(false) {
	}

	Scheduler(unsigned c) :
			counter(c), execPayload(false) {
	}

	virtual ~Scheduler() {

	}

	__inline__ void setQueueDevice(unsigned int devID,  boost::lockfree::queue< work*>* inbox) {
		INBOX[devID] = inbox;
	}

	virtual void executed(unsigned long long devID, unsigned long long wID,
			double value) {

	}

	virtual void executed(unsigned long long devID, unsigned long long wID,
			double wvalue, double timeMS) {

	}
	virtual void enqueueMultiple(unsigned devID,List<work*>* l) {
	}

	virtual bool push(unsigned devID,work* w) {
		//boost::lock_guard<boost::mutex> lock(ILOCK[devID]);
		counter++;
		return INBOX[devID]->push(w);

	}

	virtual bool pop(unsigned devID, work* &w) {
		//boost::lock_guard<boost::mutex> lock(ILOCK[devID]);
		bool r= false;
		w = NULL;
		if( INBOX[devID] != NULL && (r = INBOX[devID]->pop(w)) ) counter--;
		return r;
	}

	virtual unsigned request(unsigned devID, unsigned long long& a) {
		return 0;
	}

	virtual float assignChunk(unsigned int devID) {
		return 1.f;
	}

	virtual bool checkEligiblity(unsigned int devID, unsigned int wt) {
		return true;
	}

	virtual bool isEmpty(unsigned devID) {
		return (counter == 0);
	}

	bool allEmpty() {
//		bool reset = true;
////		printf("Counter %u [", (unsigned) counter);
//
//		for(int i=0; i < TOTAL_DEVICES; i++) {
//			reset &= (INBOX[i] != NULL && INBOX[i]->empty());
////			printf("%c,",(INBOX[i] != NULL && INBOX[i]->empty()) ? 't':'f');
//		}
//
////		printf("]\n");
//
//		if (reset) counter = 0;

		return (counter == 0);
	}

	virtual double* getModel(unsigned int wt) {
		double* ret = new double[TOTAL_DEVICES];
		double acc = 0.f;
		for (int i = 0; i < TOTAL_DEVICES - 1; i++) {
			ret[i] = LOADS[i];
			acc += ret[i];
		}
		ret[TOTAL_DEVICES - 1] = 1.f - acc;
		return ret;
	}

	virtual void normalize(bool) {
	}

	virtual void updateIdle(unsigned dev, double e, double i) {

	}

	virtual bool donate(unsigned deviceId, work* w) {

		unsigned int part;

		if (DEVICE_TYPES[deviceId]==GPU_CUDA ||  !IS_DICEABLE(w->WORK_TYPE_ID)) {
			push(deviceId,w);

			return true;
		}
		part = TOTAL_CORES_TYPES[deviceId] << DICE_SIZE;

		double* p = new double[part];
		for (int i = 0; i < part; i++) {
			p[i] = 1.f / (float) part;
		}

		ptrwork* l = w->dice(p, part);
		if (l == NULL) {
			push(deviceId,w);
		} else {
			for (unsigned jj = 0; jj < part; jj++) {
				if (l[jj] != NULL) {
					l[jj]->start = w->start;
					push(deviceId,l[jj]);
				}
			}
			delete w;
			delete l;
		}
		delete p;
		return true;

	}
};

#endif /* SCHEDULER_H_ */
