#include <DHT.h>
#include <DHT_U.h>

// TemperatureSensor.h

#ifndef _TEMPERATURESENSOR_h
#define _TEMPERATURESENSOR_h



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
	short pinA;
	dht11 DHT;

};

#endif
