/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(11520);
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Position 0
  Serial.println("setting position 0");
  myservo.write(0);
  delay(2000);

  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    Serial.println(pos);
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Serial.println(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
