/*
 * PrefModel.h
 *
 *  Created on: Dec 26, 2012
 *      Author: jbarbosa
 */

#ifndef PREFMODEL_H_
#define PREFMODEL_H_

class PerfModel {
public:
	PerfModel() {

	}
	virtual ~PerfModel() {

	}
	virtual double workdone(unsigned devID) {
		return 1.f / (double) TOTAL_DEVICES;
	}
	virtual double estimate(unsigned devID, unsigned wtype) {
		return 1.f / (double) TOTAL_DEVICES;
	}

	virtual double update(unsigned devID, unsigned wtype, double value) {
		return 1.f / (double) TOTAL_DEVICES;
	}

	virtual double totalwork(unsigned wtype) {
		return 1.f;
	}

	virtual bool normalize(bool) {
		return false;
	}

	virtual void updateIdle(unsigned int dev, double e, double i) {
	}

	virtual double* getModel(unsigned int) {
		return NULL;
	}
};

#endif /* PREFMODEL_H_ */
