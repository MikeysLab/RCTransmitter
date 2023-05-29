// 
// 
// 

#include "OLED.h"

oledScreen::oledScreen()
{
	display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
}

void oledScreen::update()
{
	//update the display
}

void oledScreen::setChannelValue(uint8_t channel, uint16_t value)
{
	if (value < 1000 || value > 2000) return;
	channels[channel] = value;
}
