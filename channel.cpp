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

bool channel::calibrate()
{
	if (_minRaw >= 0 && _maxRaw <= 1028)
	{

	}
	return false;
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

uint16_t channel::getRawValue()
{
	return _rawValue;
}

uint8_t channel::getPin()
{
	return _pinNum;
}

bool channel::attach(uint8_t pin, bool analog)
{
	pinMode(pin, INPUT);
	_pinNum = pin;

	_minVal = 1000;
	_maxVal = 2000;
	_midVal = 1500;

	_isAnalog = analog;

	_scaleValue = determineScaleValue();
	
	return true;
}

bool channel::attach(uint8_t pin, bool analog, uint16_t min, uint16_t mid, uint16_t max)
{
	_minVal = min;
	_midVal = mid;
	_maxRaw = max;
	return attach(pin, analog);
}

bool channel::update()
{
	if (_isAnalog)
	{
		uint16_t newValue = analogRead(_pinNum);
		if ((newValue < (_rawValue - _flutterValue)) || (newValue > (_rawValue + _flutterValue)))
		{
			if (newValue < _minRaw) _minRaw = newValue;
			if (newValue > _maxRaw) _maxRaw = newValue;

			_rawValue = newValue;
			return true;
		}
		return false;
	}

	_rawValue = digitalRead(_pinNum);
	return true;
}
