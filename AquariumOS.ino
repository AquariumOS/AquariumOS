//Declare libraries dependencies.

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define TEMPERATURE_PRECISION 9

// OneWire Bus Setup
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);

// Initialize OneWire for Dallas Temp Sensor 
DallasTemperature sensors(&oneWire);

// Initialize lcd screen
const int RS = 2;
const int E = 3;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

// Intialize variable
int numSensors;
float temp;

// Board Initialisation
void setup(){
	lcd.begin(16,2);
	delay(1000);
	lcd.setCursor(0, 0);
	lcd.print("Aquarium OS"); 
	lcd.setCursor(0, 1);
	lcd.print("Loading...");
	sensors.begin();
	numSensors = sensors.getDeviceCount();
	delay(1000);
	lcd.clear();
	delay(10);
}

// Main Program
void loop(){
	sensors.requestTemperatures();
	temp = sensors.getTempCByIndex(0);
	lcd.setCursor(0, 0);
	lcd.print("Temp:");
	lcd.print(temp);
	lcd.print("C");
}
