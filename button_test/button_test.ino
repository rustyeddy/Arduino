// Test a 2pole button
#define PIN_BUTTON  7

int button_pressed = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (! button_pressed ) {
    Serial.println("waiting for button to be pressed");
  }
  while(! button_pressed) {
    int p = digitalRead(PIN_BUTTON);
    if (p == 0) {
      button_pressed = true;
      Serial.println("The button has been pressed!");
    }
  }

  delay(1000);
  Serial.print(".");
  
}
