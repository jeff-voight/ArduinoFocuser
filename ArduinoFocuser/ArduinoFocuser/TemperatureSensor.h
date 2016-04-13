// TemperatureSensor.h

#ifndef _TEMPERATURESENSOR_h
#define _TEMPERATURESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <dht11.h>
#include "ArduinoCircuit.h"


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
	dht11 DHT;

};

#endif

