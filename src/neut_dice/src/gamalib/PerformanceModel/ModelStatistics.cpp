/*
 * ModelStatics.cpp
 *
 *  Created on: Apr 15, 2013
 *      Author: jbarbosa
 */

#include "ModelStatistics.h"
#include <algorithm>    // std::sort
#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 4


void ModelStatistics::add(StatNode other) {
	pq.push_back(other);
}

void ModelStatistics::shrink() {
}

double* ModelStatistics::value() {
	unsigned count = 0;
	std::sort(pq.begin(), pq.end());

	if (pq.empty()) {
		return NULL;
	}

	double* m = new double[pq.begin()->size];
	double btt = pq.begin()->time;
	double* e = pq.begin()->precent;
	double* t = pq.begin()->idle;

	for (int dev = 0; dev < pq.begin()->size; dev++) {
		m[dev] = e[dev] + e[dev] * t[dev] / btt;
	}

	double p=0.5;

	for (std::vector<StatNode>::iterator s = pq.begin() + 1;s != pq.end(); s++) {
		double tt = s->time;
		e = s->precent;
		t = s->idle;
		double aa = btt/tt;
		for (int dev = 0; dev < pq.begin()->size; dev++) {
			m[dev] = m[dev] + e[dev] * t[dev] / tt * aa;
		}
	}


//    unsigned count = 0;
//
//    std::sort(pq.begin(), pq.end());
//
//
//    unsigned SIZE = pq.begin()->size;
//    unsigned DATA_POINTS = LIST_SIZE; //pq.size();
//
//
//    double* m = new double[SIZE];
//
//    double* tTotal = new double[SIZE * DATA_POINTS];
//
//
//    for (std::vector<StatNode>::iterator s = pq.begin();s != pq.end() && count < LIST_SIZE; s++, count++) {
//            StatNode node = (*s);
//            for(unsigned i=0; i < SIZE; i++) {
//                    double tExec = node.time - node.idle[i];
//                    tTotal[i*DATA_POINTS + count] = (node.time  * node.precent[i]) / tExec;
//            }
//    }
//
//    double length = 0;
//    for(unsigned i=0; i < SIZE; i++) {
//            m[i] = 0;
//            for(unsigned j=0; j < DATA_POINTS; j++) {
//                    m[i] += tTotal[i*DATA_POINTS +j] / (float) count;
//            }
//            length+=m[i];
//    }
//
//    for(unsigned i=0; i < SIZE; i++) {
//            m[i] /= length;
//    }
//
//    delete tTotal;


	//if(pq.size()>LIST_SIZE) pq.erase(pq.end()-1/*pq.begin()+(rand() % LIST_SIZE+1)*/);

	return m;
}

void ModelStatistics::print() {
	std::sort(pq.begin(), pq.end());
//
//	std::vector<tuple>::iterator i;

	for (unsigned int i = 0; i != pq.size(); i++) {
		pq.at(i).print();
	}
	printf("\n");
	return;
}
