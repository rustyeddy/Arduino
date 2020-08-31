#include <M5Stack.h>
#include <WiFi.h>
#include <string>

// --------------------------- Network Globals --------------------
const char* ssid        = "MobileRobot";
const char* pass        = "123454321";

// --------------------------- Display Globals --------------------
int textColor = YELLOW;
int textSize  = 2;
int textX = 20;
int textY = 30;
int backgroundColor = BLACK;

// --------------------------- Buttons Globals --------------------
int thisButton = 1;
int lastButton = 0;

void printIPAddr() {
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(27, 50);
    M5.Lcd.println(WiFi.localIP());
}

void printRusty() {
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(27, 15);
    M5.Lcd.printf("Rusty Eddy");
}

void printLaser() {
    M5.Lcd.setCursor(27, 15);
    M5.Lcd.printf("Laser Emulator");
}

void (*printer)() = printLaser;



// --------------------------- Task1 -------------------------------
void task1(void * pvParameters) {
    for(;;) {
        //Serial.print("task1 Uptime (ms): ");
        //Serial.println(millis());
        delay(100);
    }
}

// ------------------- Display Task ---------------------------------
void displayTask(void * pvParameters) {
    for(;;) {
        if (lastButton != thisButton) {
            M5.Lcd.fillScreen(backgroundColor);
            M5.Lcd.setTextColor(textColor);
            printer();
            /*
            M5.Lcd.setCursor(textX, textY);
            M5.Lcd.setTextSize(textSize);
            M5.Lcd.printf(message);
            */
            lastButton = thisButton;
        }
        delay(50);
    }
}

// ------------------- Network Task ---------------------------------
void networkSetup() {
     WiFi.begin(ssid, pass);

     while (WiFi.status() != WL_CONNECTED) {
         delay(500);
         Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    //Serial.println(WiFi.localIP());
}

void networkTask(void * pvParameters) {
    networkSetup();
        
    for(;;) {
        //Serial.print("task3 Uptime (ms): ");
        //Serial.println(millis());
        delay(1000);
    }
}

// ----------------------- Setup -------------------------------------
void setup() {

    M5.begin(true, false, true);
    M5.Power.begin();

    // Task 1
    xTaskCreatePinnedToCore(task1,     /* Function to implement the task */
                            "task1",   /* Name of the task */
                            4096,      /* Stack size in words */
                            NULL,      /* Task input parameter */
                            1,         /* Priority of the task */
                            NULL,      /* Task handle. */
                            0);        /* Core where the task should run */

    // Task 2
    xTaskCreatePinnedToCore(displayTask,     /* Function to implement the task */
                            "DisplayTask",   /* Name of the task */
                            4096,      /* Stack size in words */
                            NULL,      /* Task input parameter */
                            2,         /* Priority of the task */
                            NULL,      /* Task handle. */
                            0);        /* Core where the task should run */

    // Task 3
    xTaskCreatePinnedToCore(networkTask,     /* Function to implement the task */
                            "NetworkTask",   /* Name of the task */
                            4096,            /* Stack size in words */
                            NULL,               /* Task input parameter */
                            3,         /* Priority of the task */
                            NULL,      /* Task handle. */
                            0);        /* Core where the task should run */
}

// ----------------------- Loop -------------------------------------
void loop() {
    M5.update();

    if (M5.BtnA.wasReleased()) {
        backgroundColor = BLACK;
        textColor = GREEN;
        thisButton = 1;
        printer = printRusty;
    }

    if (M5.BtnB.wasReleased()) {
        backgroundColor = WHITE;
        textColor = BLACK;
        thisButton = 2;
        printer = printIPAddr;
    }

    if (M5.BtnC.wasReleased()) {
        backgroundColor = BLUE;
        textColor = YELLOW;
        thisButton = 3;
        printer = printLaser;
    }
        
}
