/*
 * channel.h
 *
 *  Created on: Apr 3, 2012
 *      Author: jbarbosa
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "signals.h"

typedef struct _channel {

	volatile SIGNAL_DEVICE toDevice;
	volatile DEVICE_STATUS fromDevice;

	_channel() : toDevice(NULL_SIGNAL), fromDevice(DEVICE_NULL_STATUS) {

	}

} ComChannel;


#endif /* CHANNEL_H_ */
