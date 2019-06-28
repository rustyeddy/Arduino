#include <Wire.h>

#include "i2c.h"

// This should be the only file to access Wire for i2c

const int16_t PIN_I2C_SDA	= 1;
const int16_t PIN_I2C_SCK	= 2;

const int16_t I2C_MASTER	= 0x71;
const int16_t I2C_MICRO		= 0x11;
const int16_t I2C_OLED		= 0x3c;

void i2c_setup() {
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCK, I2C_MASTER);
}

void i2c_send_message(int val) {
    Wire.beginTransmission(I2C_MICRO); // transmit to device #8
    Wire.write("x is ");        // sends five bytes
    Wire.write(val);		// sends one byte
    Wire.endTransmission();	// stop transmitting
}
