/*
 * DemandScheduler.cpp
 *
 *  Created on: Aug 7, 2012
 *      Author: jbarbosa
 */
#include <config/common.h>

#include <deque>
#include <map>
#include <vector>
#include <gamalib/gamalib.h>

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include <pthread.h>



#include "DemandScheduler.h"

DemandScheduler::DemandScheduler() : Scheduler() {
	fprintf(stderr, "(SYS) Demand Driven\n");
	_model = new SDDPerfModel(TOTAL_DEVICES);
}

float DemandScheduler::assignChunk(unsigned int devID) {
	return _model->workdone(devID);
}

bool DemandScheduler::checkEligiblity(unsigned int devID, unsigned int wt) {
	double r = (double) rand() / (double) RAND_MAX;

	double prob = _model->estimate(devID, wt);
	if (prob < 0.01f)
		return false;
	return (prob > r);
}

bool DemandScheduler::checkEligiblity(unsigned int devID, unsigned int vicID,
		unsigned int wt, double Ww) {

	double r = (double) rand() / (double) RAND_MAX;

	double Ws = _model->estimate(vicID, wt);
	double Wd = _model->estimate(devID, wt);

	bool dec = (Wd >= Ws);

	return dec;
}

void DemandScheduler::executed(unsigned long long devID, unsigned long long wID,
		double value) {
	_model->update(devID, wID, value);
}

void DemandScheduler::executed(unsigned long long devID, unsigned long long wID, double wvalue, double timeMS) {
	double value = wvalue;// * timeMS;
	_model->update(devID, wID, value);
}

unsigned DemandScheduler::request(unsigned devID, unsigned long long &request) {
	unsigned int vicid = rand() % TOTAL_DEVICES;
	work* w = NULL;
	if (vicid!=devID && pop(vicid,w)) {
		donate(devID,w);
		request <<= 1;
	} else {
		request >>= 1;
	}
	return request;
}

double* DemandScheduler::getModel(unsigned int wt) {
	return _model->getModel(wt);
}
