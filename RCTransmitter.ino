/*
 Name:		RCTransmitter.ino
 Created:	5/25/2023 6:02:31 PM
 Author:	Mikey's Lab
*/
#include "defines.h"
#include "utils.h"
#include "controller.h"
#include "OLED.h"

controller controls;
oledScreen oled;

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
		displayRawValues(controls);
	}

	if (_lastTransmit + DELAY_TX_MS < millis())
	{
		//transmit the current values
		_lastTransmit = millis();
	}

	if (_lastOledUpdate + DELAY_OLED_UPDATE_MS < millis())
	{
		for (int i = 0; i < TX_NUM_CHANNELS - 1; i++)
		{
			oled.setChannelValue(i, controls.getChannelValue(i));
		}
		oled.update();
		_lastOledUpdate = millis();
	}
}

// Setup functions
void SetupSerial()
{
	Serial.begin(115200);
	identify();
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

void displayRawValues(controller control)
{
	char line[100] = "";
	sprintf(line, "0:%d\t1:%d\t2:%d\t3:%d\t4:%d\t5:%d\t", control.getChannelValue(0), control.getChannelValue(1), control.getChannelValue(2), control.getChannelValue(3), control.getChannelValue(4), control.getChannelValue(5));
	Serial.println(line);
}

void identify()
{
	char line[80];
	sprintf(line, "== RC Transmitter == V0.1 == %s %s", __DATE__, __TIME__);
	Serial.println(line);
}

// Loop functions
