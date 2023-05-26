// channel.h


#ifndef _channel_h
#define _channel_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "defines.h"

class channel {
private:
	uint8_t _rawValue = 0;

	uint8_t _pinNum;

	bool _attached = false;
	bool _isAnalog = false;

	uint16_t _minVal;
	uint16_t _maxVal;
	uint16_t _midVal;

	float _scaleValue = 0;

	float determineScaleValue();

public:
	channel();

	uint16_t getMinValue();
	uint16_t getMidValue();
	uint16_t getMaxValue();

	uint16_t getTxValue();

	bool attach(uint8_t pin, bool analog);
	bool update();
};


#endif

