// TemperatureSensor.h

#ifndef _TEMPERATURESENSOR_h
#define _TEMPERATURESENSOR_h
#include "DHT.h"
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ArduinoCircuit.h"

#define DHTTYPE DHT11

class TemperatureSensor : public ArduinoCircuit {
public:
	TemperatureSensor();
	TemperatureSensor(char _pinA);
	~TemperatureSensor();
	double getTemperature();
	double getHumidity();
	double getDewPoint();
	void refresh();

private:
	double temperature;
	double humidity;
	uint8_t pinA;
	DHT dht11 = DHT(8, DHTTYPE);

};

#endif
