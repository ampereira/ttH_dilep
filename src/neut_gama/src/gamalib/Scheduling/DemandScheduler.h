/*
 * DemandScheduler.h
 *
 *  Created on: Aug 7, 2012
 *      Author: jbarbosa
 */

#ifndef DEMANDSCHEDULER_H_
#define DEMANDSCHEDULER_H_

#include "Scheduler.h"

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include <gamalib/PerformanceModel/SDDPerfModel.h>

class DemandScheduler : public Scheduler {

protected:

	boost::mutex _lock;
	PerfModel* _model;

public:
	DemandScheduler();

	virtual ~DemandScheduler() {
		delete _model;
	}

	virtual void executed(unsigned long long devID, unsigned long long wID, double value);
	virtual void executed(unsigned long long devID, unsigned long long wID, double wvalue, double timeMS);

	virtual unsigned request(unsigned devID, unsigned long long&);

	float assignChunk(unsigned int devID);

	bool checkEligiblity(unsigned int devID, unsigned int wt);
	bool checkEligiblity(unsigned int devID, unsigned int vicID, unsigned int wt, double Ww);

    virtual double* getModel(unsigned int wt);

//	__inline__ bool allEmpty() {
//        bool all = true;
//        for(int __dev=0; __dev <  TOTAL_DEVICES; __dev++) all &= INBOX[__dev]->empty();
//		return all;
//	}

    virtual void normalize(bool t) {
    	execPayload = _model->normalize(t);
    }

    virtual void updateIdle(unsigned dev, double e, double i)  {
    	_model->updateIdle(dev, e, i);
    }
};

#endif /* DEMANDSCHEDULER_H_ */
