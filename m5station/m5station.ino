#include <M5Stack.h>
#include <WiFi.h>
#include "display.hpp"

Display *display;
int i = 0;

void task1(void * pvParameters) {

    for(;;) {
        Serial.print("task1 Uptime (ms): ");
        Serial.println(millis());
        delay(100);
    }
}

void task2(void * pvParameters) {

    for(;;) {
        Serial.print("task2 Uptime (ms): ");
        Serial.println(millis());
        delay(200);
    }
}

void task3(void * pvParameters) {

    for(;;) {
        Serial.print("task3 Uptime (ms): ");
        Serial.println(millis());
        delay(1000);
    }
}


void setup() {
    display = new Display();

    M5.begin(true, true, true, true);

    // Task 1
    xTaskCreatePinnedToCore(
                    task1,     /* Function to implement the task */
                    "task1",   /* Name of the task */
                    4096,      /* Stack size in words */
                    NULL,      /* Task input parameter */
                    1,         /* Priority of the task */
                    NULL,      /* Task handle. */
                    0);        /* Core where the task should run */

    // Task 2
    xTaskCreatePinnedToCore(
                    task2,     /* Function to implement the task */
                    "task2",   /* Name of the task */
                    4096,      /* Stack size in words */
                    NULL,      /* Task input parameter */
                    2,         /* Priority of the task */
                    NULL,      /* Task handle. */
                    0);        /* Core where the task should run */

    // Task 3
    xTaskCreatePinnedToCore(
                    task3,     /* Function to implement the task */
                    "task3",   /* Name of the task */
                    4096,      /* Stack size in words */
                    NULL,      /* Task input parameter */
                    3,         /* Priority of the task */
                    NULL,      /* Task handle. */
                    1);        /* Core where the task should run */

    int rc = WiFi.begin("MobileRobot", "123454321");
    if (rc == -1) {
	Serial.println("We are screwed");
    }
}

void loop() {

    i += 1;
    int color = 0;
    delay(5000);

    for (int i = 0; i < 5; i++) {
	switch (i % 5) {
	case 0:
	    color = WHITE;
	    break;
		
	case 1:
	    color = BLACK;
	    break;

	case 2:
	    color = GREEN;
	    break;

	case 3:
	    color = BLUE;
	    break;

	case 4:
	    color = RED;
	    break;

	}
    }
    
    display->background(color);

    M5.update();
}
