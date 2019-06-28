#pragma once

#include <ESP8266WiFi.h>

// ================================= IP =========================
// IP Address will be assigned dynamically, for now.

/*
IPAddress staticIP(192,168,1,22);
IPAddress gateway(192,168,1,9);
IPAddress subnet(255,255,255,0);
*/
void wifi_setup();
