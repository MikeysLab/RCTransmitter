#ifndef _defines_h
#define _defines_h

// Pin definitions

#define PIN_I2C_SCL						19
#define PIN_I2C_SDA						19

// Main loop processing intervals

#define DELAY_CONTROLLER_UPDATE_MS		100
#define DELAY_OLED_UPDATE_MS			100
#define DELAY_TX_MS						50
#define DELAY_RX_MS						50

// Controller config
#define TX_NUM_CHANNELS					8

// Static Values
#define MAX_ANALOG_VALUE				255

// RC Output Values
#define RC_MIN_VAL						1000
#define RC_MID_VAL						1500
#define RC_MAX_VAL						2999

// Controller defines
#define POT_FLUTTER						10
#endif