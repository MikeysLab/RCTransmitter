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
	uint16_t _rawValue = 0;

	uint8_t _flutterValue = POT_FLUTTER;

	uint8_t _pinNum;

	bool _attached = false;
	bool _isAnalog = false;

	uint16_t _minVal = 1000;
	uint16_t _maxVal = 2000;
	uint16_t _midVal = 1500;

	uint16_t _minRaw;
	uint16_t _maxRaw;

	float _scaleValue = 0;

	float determineScaleValue();

public:
	channel();

	bool calibrate();

	uint16_t getMinValue();
	uint16_t getMidValue();
	uint16_t getMaxValue();

	uint16_t getTxValue();

	uint16_t getRawValue();

	uint8_t getPin();

	bool attach(uint8_t pin, bool analog);
	bool attach(uint8_t pin, bool analog, uint16_t min, uint16_t mid, uint16_t max);

	bool update();
};


#endif

