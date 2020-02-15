
// 
// 
// 

#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
{
}

TemperatureSensor::TemperatureSensor(uint8_t _pinA)
{
	pinA = _pinA;
	dht11.begin();
}

TemperatureSensor::~TemperatureSensor()
{
}

double TemperatureSensor::getTemperature()
{
	return dht11.readTemperature();
}
