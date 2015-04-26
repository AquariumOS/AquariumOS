//Declare libraries dependencies.

#include <LiquidCrystal.h>
#include <OneWire.h>

// OneWire Bus Setup
#define DS18B20 0x28
#define BROCHE_ONEWIRE 7

OneWire ds(BROCHE_ONEWIRE);

//Function to Get Temperature from Temperature sensor.
boolean getTemperature(float *temp){
	byte data[9], addre[8];

	if (!ds.search(addr)){
		ds.reset_search();
		return false;
	}

	if (OneWire::crc8(addr, 7) != addr[7]){
		return false;
	}

	if (addr[0] != DS18B20){
		return false;
	}

	ds.reset();
	ds.select(addr);

	ds.write(0x44, 1);
	delay(800);

	ds.reset();
	ds.select(addr);
	ds.write(0xBE);

	for (byte i = 0; i < 9; i++)
		data[i] = ds.read();

	*temp = ((data[1] << 8) | data[0]) * 0.0625;

	return true;
}

// Board Initialisation
void setup(){
	Serial.begin(9600);
}

// Main Program
void loop(){
	float temp;

	if (getTemperature(&temp)){
		Serial.print("Temp : ");
		Serial.print(temp);
		Serial.write(176); // 176 = Character °
		Serial.write('C');
		Serial.println();
	}
}
