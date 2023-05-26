/*
 Name:		RCTransmitter.ino
 Created:	5/25/2023 6:02:31 PM
 Author:	Mikey's Lab
*/
#include "defines.h"
#include "utils.h"
#include "controller.h"

controller controls;

long _lastControllerUpdate = millis();
long _lastTransmit = millis();
long _lastOledUpdate = millis();
//long _lastRecieve = millis();

// the setup function runs once when you press reset or power the board
void setup() {
	SetupSerial();
	identify();
	SetupController();
	SetupNRF();
	SetupOLED();
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (_lastControllerUpdate + DELAY_CONTROLLER_UPDATE_MS < millis())
	{
		if (controls.update()) _lastControllerUpdate = millis();
	}

	if (_lastTransmit + DELAY_TX_MS < millis())
	{
		//transmit the current values
		_lastTransmit = millis();
	}

	if (_lastOledUpdate + DELAY_OLED_UPDATE_MS < millis())
	{
		//update the display
		_lastOledUpdate = millis();
	}
}

// Setup functions
void SetupSerial()
{
	Serial.begin(115200);
}

void SetupController()
{
	controls.setup();
}

void SetupNRF()
{

}

void SetupOLED()
{

}

void identify()
{
	char line[80];
	sprintf(line, "== RC Transmitter == V0.1 == %s %s", __DATE__, __TIME__);
	Serial.println(line);
}

// Loop functions
