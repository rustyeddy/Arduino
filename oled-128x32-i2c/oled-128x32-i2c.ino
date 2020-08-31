/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Time.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static String months[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec",
};

int redPin = 5;
float temp = 7.00;

String timestr = "11:12";
String datestr = "Feb 20";

void setup() {
    Serial.begin(115200);
    pinMode(redPin, OUTPUT);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
	Serial.println(F("SSD1306 allocation failed"));
	for(;;); // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.clearDisplay();
    drawText();
}

void loop() {

    digitalWrite(redPin, HIGH);

    // send data only when you receive data:
    if (Serial.available() > 0) {

	String key = Serial.ReadTo(":");
	String val = Serial.ReadLine();

	// say what you got:
	Serial.print("I received: ", t, v);
	switch (t) {
	case KEY_TIME:
	    timestr = val; // used in drawText
	    break;

	case KEY_DATE:
	    datestr = val; // used in drawText
	    break;
	}
    }
    temp = get_voltage();
    Serial.println("temp: ", temp);

    drawText();
    digitalWrite(redPin, LOW);
    delay(10000);
}

float get_voltage()
{
    int sample_count = 64;
    float temp = 0.0;
    
    // lets loop around and take an average
    for (int i = 0; i < 64; i++ ) {

	int sensorValue = analogRead(A1);

	// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.3V):
	float voltage = sensorValue * (5.0 / 1023.0);

	// print out the value you read:
	Serial.println(voltage);
	temp += voltage * 100.0;
    }

    temp /= sample_count;
    return temp;
}

void drawText() {
   display.clearDisplay();
    
    display.setTextSize(1); // Draw 2X-scale text
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(10, 0);
    display.println(datestr);

    display.setCursor(90, 0);
    display.print(timestr);

    display.setTextSize(2);
    display.setCursor(35, 15);
    display.print(temp);
    display.display();
}

