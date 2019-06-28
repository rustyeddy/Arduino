#include <Wire.h>
#include <PolledTimeout.h>

#include "wifi.h"
#include "i2c.h"


void setup(void)
{
    Serial.begin(115200);
    Serial.println();

    wifi_setup();
    i2c_setup();

}

byte x = 0;
void loop() {
    Wire.requestFrom(I2C_MICRO, 6); // request 6 bytes from slave device #8

    while (Wire.available()) {
	int v = Wire.read();
	if (v == 'J') {
	    // read the joy stick values
	    int h = Wire.read();
	    int v = Wire.read();
	    int b = Wire.read();
	}
	Serial.printf("got joystick values <%x, %x, %d>\n", h, v, b);

	// Add these to the summation stream 
    }
    delay(100);
}
