/*
 * SDDPerfModel.cpp
 *
 *  Created on: Dec 26, 2012
 *      Author: jbarbosa
 */
#include <config/common.h>
#include "SDDPerfModel.h"

#include <math.h>

#define ABS(A) ( (A<0) ? -A : A)

SDDPerfModel::SDDPerfModel(unsigned devices) :
		tDevices(devices), _count(0) {
	for (unsigned dev = 0; dev < tDevices; dev++) {
		for (unsigned wt = 0; wt < WORK_TOTAL; wt++) {
			_model[dev][wt].exchange(LOADS[dev]);
		}
	}
	for (unsigned dev = 0; dev < tDevices; dev++) {
		_exec[dev] = 0.0f;
		_idle[dev] = 0.0f;
		_ready[dev] = false;
	}
}

SDDPerfModel::~SDDPerfModel() {
	printModel();
}

void SDDPerfModel::printModel() {

	double m[WORK_TOTAL][TOTAL_DEVICES];
	for (unsigned wt = 1; wt < WORK_TOTAL; wt++) {
		double t = totalwork(wt);

		for (int dev = 0; dev < tDevices; dev++) {
			m[wt][dev] = _model[dev][wt] / t;
		}
	}

	for (int dev = 0; dev < tDevices; dev++) {
		fprintf(stderr, "Device %s \t", (DEVICE_TYPES[dev] == CPU_X86) ? "CPU" : "GPU");
		for (unsigned wt = 1; wt < WORK_TOTAL; wt++) {
			fprintf(stderr, "(%3f)\t", m[wt][dev]);
		}
//		double idle = _idle[dev];
//		fprintf(stderr, "%8f\t", idle);
		fprintf(stderr, "\n");
	}

	for (int wt = 1; wt < WORK_TOTAL; wt++) {
		fprintf(stderr, "Work %u \n", wt);
		HistoryStats[wt].print();
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "%d \n", _count + 0);
}

double SDDPerfModel::workdone(unsigned devID) {
	double total = 0.f;
	double total_dev = 0.f;

	for (unsigned dev = 0; dev < tDevices; dev++) {
		for (unsigned wt = 0; wt < WORK_TOTAL; wt++) {
			total += _model[dev][wt];
			if (devID == dev)
				total_dev += _model[dev][wt];
		}
	}

	if (total == 0.f)
		return 1.f;
	return (total_dev / total);
}

double SDDPerfModel::estimate(unsigned devID, unsigned wtype) {

	if (devID == tDevices)
		return 1.f / (double) tDevices;

	double tTotal = 0.0;
	double tDevice = 0.0;
	double tWType = 0.0;

	double maxwt = -1.0;
	for (unsigned dev = 0; dev < tDevices; dev++) {
		for (unsigned wt = 0; wt < WORK_TOTAL; wt++) {
			tTotal += _model[dev][wt];
			if (dev == devID)
				tDevice += _model[dev][wt];
			if (wt == wtype)
				tWType += _model[dev][wt];
		}
	}
	return _model[devID][wtype] / tWType;
}

double SDDPerfModel::update(unsigned devID, unsigned wtype, double value) {
	double prop = 1.0f;
	double invprop = 1.0f;

	double a = _model[devID][wtype];
	double n = a * prop + value * invprop;
	while (!_model[devID][wtype].compare_exchange_weak(a, n)) {
		a = _model[devID][wtype];
		n = a * prop + value * invprop;
	}
	return a;
}

double SDDPerfModel::totalwork(unsigned wt) {
	double tTotal = 0.f;
	for (unsigned dev = 0; dev < tDevices; dev++) {
		tTotal += _model[dev][wt];
	}
	return tTotal;
}

bool SDDPerfModel::normalize(bool exec) {
	if (!exec) return false;
	_count++;
	double tTotal = 0.0f;

	double prop = 1.f / (float) TOTAL_DEVICES;

	double tIdle = 0.0f;

	for (unsigned dev = 0; dev < tDevices; dev++) {
		while(!_ready[dev]);
		tTotal = MAX(_exec[dev],tTotal);
		tIdle += _idle[dev];
		_ready[dev] = false;
	}

	for (unsigned wt = 1; wt < WORK_TOTAL; wt++) {
		double t = totalwork(wt);

		for (int dev = 0; dev < tDevices; dev++) {
			_model[dev][wt] = _model[dev][wt] / t;
		}
	}


	for (unsigned wt = 1; wt < WORK_TOTAL; wt++) {
		double* idle = new double[TOTAL_DEVICES];
		double* cur = new double[TOTAL_DEVICES];
		for (unsigned dev = 0; dev < tDevices; dev++) {
			idle[dev] = _idle[dev] * _model[dev][wt];
			cur[dev] = _model[dev][wt];
		}
		HistoryStats[wt].add(StatNode(_count,tTotal, idle, cur, TOTAL_DEVICES));
	}

	for (unsigned wt = 1; wt < WORK_TOTAL; wt++) {
		double* cur = HistoryStats[wt].value();
		if (cur == NULL) continue;
		for (unsigned dev = 0; dev < tDevices; dev++) {
			_model[dev][wt] = cur[dev]; // (_model[dev][wt] + (_idle[dev] / tTotal) *_model[dev][wt]  + cur[dev]) * 0.5f;
		}
	}

//	for (unsigned wt = 1; wt < WORK_TOTAL; wt++) {
//		tTotal = totalwork(wt);
//		for (unsigned dev = 0; dev < tDevices; dev++) {
//			_model[dev][wt] = _model[dev][wt] / tTotal;
//		}
//	}

	return false;

}

void SDDPerfModel::updateIdle(unsigned int dev, double e, double i) {
	_exec[dev] = e;
	_idle[dev] = i;
	_ready[dev] = true;
}

double* SDDPerfModel::getModel(unsigned int wt) {
	double* ret = new double[TOTAL_DEVICES];
	double acc = 0.f;
	double tWork = 0.f;

	double tTotal = totalwork(wt);
	if (tTotal == 0) {
		for (int i = 0; i < TOTAL_DEVICES; i++) {
			ret[i] = 1.f / (float) TOTAL_DEVICES;
		}
		return ret;
	}
	for (int i = 0; i < TOTAL_DEVICES; i++) {
		ret[i] = _model[i][wt];
		ret[i] = (ret[i] < 0.f) ? 0.f : ret[i];
		ret[i] = (ret[i] > 1.f) ? 1.f : ret[i];
		tWork += ret[i];
	}

	for (int i = 0; i < TOTAL_DEVICES; i++) {
		ret[i] = _model[i][wt] = floor(ret[i] / tWork * 100.f) / 100.f;



	}
	return ret;
}
