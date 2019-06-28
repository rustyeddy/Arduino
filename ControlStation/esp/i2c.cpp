#include <Wire.h>

#include "../i2c.h"

void i2c_setup() {
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCK, I2C_MASTER);
}

void i2c_send_message(int val) {
    Wire.beginTransmission(I2C_MICRO); // transmit to device #8
    Wire.write("x is ");        // sends five bytes
    Wire.write(val);		// sends one byte
    Wire.endTransmission();	// stop transmitting
}
