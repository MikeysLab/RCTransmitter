// 
// 
// 

#include "channel.h"

float channel::determineScaleValue()
{
	if (_isAnalog)
	{
		//analog values can be between 0 and 255, determine the maximum delta of output scale and divide by max input value to get a number to multiply the
		//input by to output a comperable output value
		return (_maxVal - _minVal) / MAX_ANALOG_VALUE;
	}
	else
	{
		//digital values are either 0 or max output values, return a scale to convert 1 to the max output value
		return _maxVal - _minVal;
	}
}

channel::channel()
{
}

uint16_t channel::getMinValue()
{
	return uint16_t();
}

uint16_t channel::getMidValue()
{
	return uint16_t();
}

uint16_t channel::getMaxValue()
{
	return uint16_t();
}

uint16_t channel::getTxValue()
{
	return _rawValue * _scaleValue + _minVal;
}

bool channel::attach(uint8_t pin, bool analog)
{
	pinMode(pin, INPUT);
	_pinNum = pin;

	_minVal = RC_MIN_VAL;
	_maxVal = RC_MID_VAL;
	_midVal = RC_MAX_VAL;

	_isAnalog = analog;

	_scaleValue = determineScaleValue();
	
	return true;
}

bool channel::update()
{
	_rawValue = _isAnalog ? analogRead(_pinNum) : digitalRead(_pinNum);
	return true;
}
