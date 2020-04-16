#include <M5Stack.h>

void task1(void * pvParameters) {

    for(;;) {
        Serial.print("task1 Uptime (ms): ");
        Serial.println(millis());
        delay(100);
    }
}

void displayTask(void * pvParameters) {
    Serial.print("Display Task Uptime (ms): ");
    Serial.println(millis());

    M5.Lcd.fillScreen(BLACK);

    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.setTextSize(2);
    M5.Lcd.printf("Laser Emulator");

    for(;;) {
        delay(500);
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

    M5.begin();
    M5.Power.begin();

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
                    displayTask,     /* Function to implement the task */
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
                    0);        /* Core where the task should run */
}

void loop() {
    M5.update();
}
