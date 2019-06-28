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
    using periodic = esp8266::polledTimeout::periodicMs;
    static periodic nextPing(1000);

    if (nextPing) {
	Serial.printf("writing x %x\r\n", x);
	i2c_send_message(x);
	x++;
    }
    delay(100);
}
