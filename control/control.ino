/*	-*- c++ -*-

  File: control.ino
  
  This sketch reads <x, y> inputs from a Joystick and translates them
  into pan-tilt motion on the corresponding camera.  Currently the
  speed and acceleration of the servos directly reflects the relative 
  speed, acceleration and position as the corresponding P&T mechanism.

*/

#include <Arduino.h>
#include <Servo.h>

// -------------------------- Pin settings ---------------------------

const int pin_joy_sw		= 2;
const int pin_joy_horz		= 4;
const int pin_joy_vert		= 5;

const int pin_servo_horz	= 9;
const int pin_servo_vert	= 10;

// ----------------------- Globals Variables--------------------------
Servo servo_horz;
Servo servo_vert;

// ----------------------------- Setup -------------------------------
void setup() {
    Serial.begin(115200);

    pinMode(pin_joy_sw, INPUT);
    pinMode(pin_joy_horz, INPUT);
    pinMode(pin_joy_vert, INPUT);

    servo_horz.attach(pin_servo_horz);
    servo_vert.attach(pin_servo_vert);
}

// ----------------------------- Loop -------------------------------
void loop() {
    Serial.println("toop lop");

    // Get raw numbers from joy stick
    unsigned long x = analogRead(pin_joy_horz);
    unsigned long y = analogRead(pin_joy_vert);
    unsigned int  s = digitalRead(pin_joy_sw);

    Serial.print(x); Serial.print(" ");
    Serial.print(y); Serial.print(" ");
    Serial.println(s);

    x = map(x, 1, 1023, 0, 180);
    y = map(y, 1, 1023, 0, 180);
    
    servo_horz.write(x);
    servo_vert.write(y);
    delay(15);
}
