//Declare libraries dependencies.

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// OneWire Bus Setup
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);

// Initialize OneWire 
DallasTemperature sensors(&oneWire);

// Board Initialisation
void setup(){
	Serial.begin(9600);
	Serial.println("Aquarium OS V0.0.1");
	Serial.println("Ready");
}

// Main Program
void loop(){
	sensors.requestTemperatures();
	Serial.println(sensors.getTempCByIndex(0));
}
