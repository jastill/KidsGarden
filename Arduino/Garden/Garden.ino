/* 
 *  Garden water controller with Light and Moisture Sensor.
 *  
 *  http://www.seeedstudio.com/wiki/Relay_Shield_V2.0#How_Relay_works
 *  
 *  Digital 4 – controls RELAY4’s COM4 pin (located in J4)
 *  Digital 5 – controls RELAY3’s COM3 pin (located in J3)
 *  Digital 6 – controls RELAY2’s COM2 pin (located in J2)
 *  Digital 7 – controls RELAY1’s COM1 pin (located in J1)
 */

int pumpControl = 4;    // Digital Arduino Pin used to control the motor
int lightPin = 0;
 
/**
 * Setup the board
 */
void setup()  {
    // declare the pump control pin to be an output so that we can control the relay
    pinMode(pumpControl, OUTPUT);
}
 
/**
 * Main loop. This runs forever, well until the batteries run out.
 */
void loop()  {

    // Check the soil moisture every 60s

    // Read the light value. The more light there is, the higher this value
    int lightVal = readLight();

    // Control the pump relay
    if (lightVal > 600) {
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
}

/**
 * This function turns off the water pump relay.
 */
void turnPumpOff() {
    digitalWrite(pumpControl,LOW);// NO3 and COM3 Disconnected (the motor is not running)
}

int readLight() {
  return analogRead(lightPin);
}

