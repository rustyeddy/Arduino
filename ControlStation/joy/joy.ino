#include <Wire.h>

#define I2C_MICRO	0x11
#define I2C_MASTER	0x71

#define PIN_JOY_H	A0
#define PIN_JOY_V	A1
#define PIN_JOY_B	2

const int16_t ouraddr	= I2C_MICRO;
int joypos[3];

class Joystick {
private:
    int pin_h, pin_v, pin_b;
    int h, v, b;


public:
    Joystick(int ph, pv, pb) {
	pin_h = ph;
	pin_v = pv;
	pin_b = pb;

	pinMode(ph, INPUT);
	pinMode(pv, INPUT);
	pinMode(pb, INPUT);
    }

    int *getpos() {
	joypos[0] = analogRead(PIN_JOY_H);
	joypos[1] = analogRead(PIN_JOY_V);
	joypos[2] = digitalRead(PIN_JOY_B);
	return &joypos;
    }
};

Joystick joy(PIN_JOY_H, PIN_JOY_V, PIN_JOY_B);

void requestEvent() {
    Wire.write()
}

void setup() {

    // Setup I2C for writing
    Wire.begin(I2C_MICRO);	  // join i2c bus
    //Wire.onReceive(receiveEvent); // register event
    Wire.onRequest(requestEvent);
    Serial.begin(115200);	  // start serial for output
}

void loop() {

    delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {

    // loop through all but the last
    while (1 < Wire.available()) {

	// Write the latest joy stick positions
	int *v = joy.getpos();
	Wire.Write('J');
	Wire.Write(*v++);
	Wire.Write(*v++);
	Wire.Write(*v++);
    }
    Serial.println(x);		// print the integer
}
