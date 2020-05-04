
#include <OneWire.h>
#include <Wire.h>
#include <DallasTemperature.h>
 
// Data wire for temp sensor is plugged into pin F6 on the Teensy 2.0
// Data wire for Relay is plugged into pin B6 on the Teensy 2.0
#define ONE_WIRE_BUS 17 // Temperature Sensor on F6 on the Teensy 2.0
#define RELAY1 15 // Relay for AC on B6 on the Teensy 2.0
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();
  pinMode(RELAY1, OUTPUT);
}
 
 
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  float temperature = sensors.getTempFByIndex(0);
  Serial.println("DONE");

//  Serial.print("Celcius temp: ");
//  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
  Serial.print("Fahrenheit temp: ");
  Serial.println(sensors.getTempFByIndex(0));
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire


    if(temperature < 73)
    {
 
  digitalWrite(RELAY1,1);    
  Serial.println("A/C Off");

  delay(300000);
  
           }
    else if(temperature > 73)
    {
      
  digitalWrite(RELAY1,0);
  Serial.println("A/C On");

  delay(300000);
  
}     
  //delay(1000);
}
