// Controller.h

#ifndef _Controller_h
#define _Controller_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "channel.h"

class controller {
private:
	channel channels[TX_NUM_CHANNELS];

public:
	controller();
	uint8_t getChannelPin(uint8_t channel);

	bool setup();
	bool update();
	uint16_t getChannelValue(uint8_t channel);
};

#endif

