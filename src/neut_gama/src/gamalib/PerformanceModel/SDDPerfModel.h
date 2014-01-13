/*
 * SDDPerfModel.h
 *
 *  Created on: Dec 26, 2012
 *      Author: jbarbosa
 */

#ifndef SDDPERFMODEL_H_
#define SDDPERFMODEL_H_

#include "ModelStatistics.h"
#include "PerfModel.h"
#include <boost/atomic.hpp>
#include <gamalib/mutex/atomics.h>

class SDDPerfModel : public PerfModel {

	unsigned tDevices;

	ModelStatistics HistoryStats[WORK_TOTAL];
	boost::atomic<unsigned> _count;
	boost::atomic<double> _model[TOTAL_DEVICES][WORK_TOTAL];
	volatile double _exec[TOTAL_DEVICES];
	volatile double _idle[TOTAL_DEVICES];
	volatile bool _ready[TOTAL_DEVICES];

public:
	SDDPerfModel(unsigned devices);
	virtual ~SDDPerfModel();

	virtual double workdone(unsigned devID);
	virtual double estimate(unsigned devID, unsigned wtype);
	virtual double update(unsigned devID, unsigned wtype, double value);

	virtual double totalwork(unsigned wtype);

	virtual bool normalize(bool);
	virtual void updateIdle(unsigned,double,double);
	virtual void printModel();
	virtual double* getModel(unsigned int);
};

#endif /* SDDPERFMODEL_H_ */
