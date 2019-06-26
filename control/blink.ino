#define PIN_LED LED_BUILTIN

void setup() {
    Serial.begin(115200);
    pinMode(PIN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

    Serial.println("On");
    digitalWrite(PIN_LED, HIGH);
    delay(5000);  
    Serial.println("Set low");
    digitalWrite(PIN_LED, LOW);  
}
