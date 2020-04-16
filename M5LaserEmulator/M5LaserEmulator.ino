#include <M5Stack.h>

int textColor = YELLOW;
int textSize  = 2;
int textX = 20;
int textY = 30;
int backgroundColor = BLACK;
const char *message = "Laser Emulator";

int thisButton = 1;
int lastButton = 0;

void task1(void * pvParameters) {

    for(;;) {
        Serial.print("task1 Uptime (ms): ");
        Serial.println(millis());
        delay(100);
    }
}

void displayTask(void * pvParameters) {
    for(;;) {
        if (lastButton != thisButton) {
            M5.Lcd.fillScreen(backgroundColor);
            M5.Lcd.setTextColor(textColor);
            M5.Lcd.setCursor(textX, textY);
            M5.Lcd.setTextSize(textSize);
            M5.Lcd.printf(message);
            lastButton = thisButton;
        }
        delay(50);
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

    M5.begin(true, false, true);
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

    if (M5.BtnA.wasReleased()) {
        backgroundColor = BLACK;
        textColor = GREEN;
        message = "Laser Emulator";
        thisButton = 1;
    }

    if (M5.BtnB.wasReleased()) {
        backgroundColor = WHITE;
        textColor = BLACK;
        message = "Rusty Eddy";
        thisButton = 2;
    }

    if (M5.BtnC.wasReleased()) {
        backgroundColor = BLUE;
        textColor = YELLOW;
        message = "Super Duper";
        thisButton = 3;
    }
        
}
