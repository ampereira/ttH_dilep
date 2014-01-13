/*
 * ModelStatics.h
 *
 *  Created on: Apr 15, 2013
 *      Author: jbarbosa
 */

#ifndef MODELSTATICS_H_
#define MODELSTATICS_H_

#include <vector>
#include "StatNode.h"

class ModelStatistics {

	std::vector<StatNode> pq;

public:
	ModelStatistics() {

	}
	virtual ~ModelStatistics() {

	}
	virtual void add(StatNode other);
	virtual void shrink();
	virtual double* value();
	virtual void print();
};

#endif /* MODELSTATICS_H_ */
