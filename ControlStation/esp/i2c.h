#pragma once

#include <Wire.h>

// This should be the only file to access Wire for i2c
#define PIN_ESP_I2C_SDA	1
#define PIN_ESP_I2C_SCK	2

#define I2C_MASTER	0x71
#define I2C_MICRO	0x11
#define I2C_OLED	0x3c

void i2c_setup();
void i2c_send_message(int val);
