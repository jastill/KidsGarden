/* 
 *  Garden water controller with Light and Moisture Sensor.
 *  
 *  The light sensor with 1K resistor
 *  https://learn.adafruit.com/photocells/using-a-photocell
 *  
 *  http://www.seeedstudio.com/wiki/Relay_Shield_V2.0#How_Relay_works
 *  
 *  Digital 4 – controls RELAY4’s COM4 pin (located in J4)
 *  Digital 5 – controls RELAY3’s COM3 pin (located in J3)
 *  Digital 6 – controls RELAY2’s COM2 pin (located in J2)
 *  Digital 7 – controls RELAY1’s COM1 pin (located in J1)
 */

int pumpControl = 4;    // Digital Arduino Pin used to control the motor
int lightPin = 0;       // Analog Pin 0
int moisturePin = 1;    // Analog Pin 1

#define MINMOISTURE 200
 
/**
 * Setup the board
 */
void setup()  {
    // declare the pump control pin to be an output so that we can control the relay
    pinMode(pumpControl, OUTPUT);

    // Start with the pump Off
    turnPumpOff();

    // For debugging
    Serial.begin(9600);  
}
 
/**
 * Main loop. This runs forever, well until the batteries run out.
 */
void loop()  {

    // Check the soil moisture every 60s

    // Read the light value. The more light there is, the higher this value
    int lightValue = readLight();
    Serial.print("Light reading = ");
    Serial.println(lightValue);  

    int moistureValue = readMoisture();
    Serial.print("Moisture reading = ");
    Serial.println(moistureValue);  

    // If the ground is too dry, water it
    if (moistureValue < MINMOISTURE) {
      turnPumpOn();
    } else {
      turnPumpOff();
    }
    
    delay(1000);
}

/**
 * This function turns on the water pump relay.
 */
void turnPumpOn() {
    digitalWrite(pumpControl,HIGH);// NO3 and COM3 Connected (the motor is running)
    Serial.println("Pump ON");
}

/**
 * This function turns off the water pump relay.
 */
void turnPumpOff() {
    digitalWrite(pumpControl,LOW);// NO3 and COM3 Disconnected (the motor is not running)
    Serial.println("Pump OFF");
}

/**
 * Read the value from the analog pin connected to the light sensor
 */
int readLight() {
  return analogRead(lightPin);
}

/**
 * Read the value from the analog pin connected to the moisture sensor
 */
int readMoisture() {
  return analogRead(moisturePin);
}

