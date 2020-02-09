#include <DHT_U.h>
#include <DHT.h>

// TemperatureSensor.h

#ifndef _TEMPERATURESENSOR_h
#define _TEMPERATURESENSOR_h
#include <DHT.h>

#define DHTTYPE DHT11

class TemperatureSensor  {
public:
	TemperatureSensor();
	TemperatureSensor(uint8_t _pinA);
	~TemperatureSensor();
	double getTemperature();

private:
	double temperature;
	uint8_t pinA;
	DHT dht11 = DHT(8, DHTTYPE);
};

#endif
