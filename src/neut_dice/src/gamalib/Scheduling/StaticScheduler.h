/*
 * StaticScheduler.h
 *
 *  Created on: Dec 13, 2012
 *      Author: jbarbosa
 */

#ifndef STATICSCHEDULER_H_
#define STATICSCHEDULER_H_

#include "Scheduler.h"


class StaticScheduler : public Scheduler {

public:
	StaticScheduler();
	virtual ~StaticScheduler();

	void enqueueMultiple(List<work*>* l);
	void enqueue(work* l);
};

#endif /* STATICSCHEDULER_H_ */
