// 
// 
// 

#include "Controller.h"

controller::controller()
{
}

bool controller::setup()
{
	return(channels[0].attach(PIN_A0, true) &&
		channels[1].attach(PIN_A1, true) &&
		channels[2].attach(PIN_A2, true) &&
		channels[3].attach(PIN_A3, true) &&
		channels[4].attach(PIN_A6, true) &&
		channels[5].attach(PIN_A7, true) &&
		channels[6].attach(PIN2, false) &&
		channels[7].attach(PIN3, false));
}

bool controller::update()
{
	for (int i = 0; i < (sizeof(channels) / sizeof(channel)); i++)
	{
		if (!channels[i].update()) return false;
	}
	return true;
}
