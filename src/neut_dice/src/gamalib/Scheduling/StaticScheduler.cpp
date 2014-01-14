/*
 * StaticScheduler.cpp
 *
 *  Created on: Dec 13, 2012
 *      Author: jbarbosa
 */
#include <config/common.h>
#include <vector>
#include <gamalib/gamalib.h>
#include <gamalib/work/work.h>
#include "Scheduler.h"
#include "StaticScheduler.h"

StaticScheduler::StaticScheduler() : Scheduler()
{
	fprintf(stderr, "(SYS) Static Scheduler\n");

}

StaticScheduler::~StaticScheduler()
{

}

void StaticScheduler::enqueueMultiple(List<work*> *l) {
	unsigned int size=l->_size;
	unsigned int unit = 0;
	unsigned int next = 0;
	for(;unit < size; unit++) INBOX[unit % TOTAL_DEVICES]->push((*l)[unit]);
}

//void StaticScheduler::enqueue(work *w) {
//	INBOX[0]->push(w);
//}


