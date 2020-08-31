/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#define PIN_GREEN 5
#define PIN_YELLOW 6
#define PIN_RED 7

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_YELLOW, ON);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(PIN_YELLOW, OFF);    // turn the LED off by making the voltage LOW
  delay(1000); 
  Serial.println("round and round we go...");// wait for a second
}
