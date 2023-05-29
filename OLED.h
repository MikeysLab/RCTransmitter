// OLED.h

#ifndef _OLED_h
#define _OLED_h

#define SCREEN_WIDTH			128 // OLED display width, in pixels
#define SCREEN_HEIGHT			64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET				-1 // Reset pin # (or -1 if sharing Arduino reset pin)

#include "defines.h"
#include <wire.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class oledScreen {
private:
	Adafruit_SSD1306 display;
	uint16_t channels[TX_NUM_CHANNELS];

public:
	oledScreen();

	void update();

	void setChannelValue(uint8_t channel, uint16_t value);
};

#endif

