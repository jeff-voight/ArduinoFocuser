

// TemperatureSensor.h

#ifndef _TEMPERATURESENSOR_h
#define _TEMPERATURESENSOR_h
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11

class TemperatureSensor : public ArduinoCircuit {
public:
	TemperatureSensor();
	TemperatureSensor(uint8_t _pinA);
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
