#include <Arduino.h>
#include "wifi.h"

const char* ssid = "MobileRobot";
const char* password = "123454321";

void wifi_setup() {

    Serial.printf("Connecting to %s\n", ssid);
    // WiFi.config(staticIP, gateway, subnet);
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
	delay(500);
	Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
    WiFi.reconnect();
    while (WiFi.status() != WL_CONNECTED) {
	delay(500);
	Serial.print(".");
    }
}
