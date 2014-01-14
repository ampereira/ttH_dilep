#include "StatNode.h"
#include <stdio.h>


bool StatNode::operator<(const StatNode& other) const {
       double a = time;
       double b = other.time;
       //if( a == b ) return (precent>other.precent);
       return (a<b);
}

void StatNode::print() {
	printf("%u\t%f\t",timestamp,time);

	for(unsigned i =0 ; i < size; i++) {
    	printf("%f\t",idle[i]);
    }

	for(unsigned i =0 ; i < size; i++) {
    	printf("%f\t",precent[i]);
    }

    printf("\n");
	return;
}
