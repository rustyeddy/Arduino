
// TMP36 Pin Variables the analog pin the TMP36's Vout (sense) pin is
// connected to
int sensorPin = A0;

// the resolution is 10 mV / degree centigrade with a
// 500 mV offset to allow for negative temperatures
 
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
    Serial.begin(115200);
}
 
void loop()
{
    //getting the voltage reading from the temperature sensor
    int reading = analogRead(sensorPin);  
 
    // converting that reading to voltage, for 3.3v arduino use 3.3
    float voltage = reading * 5.0;
    voltage /= 1024.0; 

    float tempc = (voltage - 0.5) * 100 ; 
    float tempf = (tempc * 9.0 / 5.0) + 32.0;

    Serial.println("v:" + String(voltage) +
		   "+c:" + String(tempc) +
		   "+f:" + String(tempf) + ";");
 
    delay(5000);                                     //waiting a second
}
