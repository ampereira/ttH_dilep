/*
 * StatNode.h
 *
 *  Created on: Apr 16, 2013
 *      Author: jbarbosa
 */

#ifndef STATNODE_H_
#define STATNODE_H_



class StatNode {

public:
	double time;
	double* idle;
	double* precent;
	unsigned int size;
	unsigned int timestamp;

	StatNode() : size(0) {
	}
	StatNode(const StatNode &other) {
		time = other.time;
		idle = other.idle;
		precent = other.precent;
		size = other.size;
		timestamp = other.timestamp;
	}

	StatNode(unsigned tp, double t, double* i, double* p, unsigned s) : time(t), idle(i), precent(p), size(s), timestamp(tp) {
	}

	~StatNode() {
	}

	 bool operator<(const StatNode& other) const;

	 void print();
};


#endif /* STATNODE_H_ */
