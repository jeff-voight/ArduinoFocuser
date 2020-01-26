// TemperatureSensor.h

#ifndef _TEMPERATURESENSOR_h
#define _TEMPERATURESENSOR_h


#include "arduino.h"
#include "ArduinoCircuit.h"
#include <DHTlib\dht.h>

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
	dht DHT;

};

#endif

