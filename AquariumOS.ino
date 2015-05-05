//Declare libraries dependencies.

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define TEMPERATURE_PRECISION 9

// OneWire Bus Setup
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);

// Initialize OneWire for Dallas Temp Sensor 
DallasTemperature sensors(&oneWire);

int numSensors;
float temp;

// Board Initialisation
void setup(){
	Serial.begin(9600);
	Serial.println("Aquarium OS V0.0.1");
	sensors.begin();
	numSensors = sensors.getDeviceCount();
	Serial.println("Ready");
}

// Main Program
void loop(){
	sensors.requestTemperatures();
	temp = sensors.getTempCByIndex(0);
	Serial.println(temp);
}
