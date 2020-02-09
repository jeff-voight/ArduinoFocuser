
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

double TemperatureSensor::getHumidity()
{
	return dht11.readHumidity();
}

double TemperatureSensor::getDewPoint()
{
	return dht11.computeHeatIndex(getTemperature(), getHumidity(), false);
}

void TemperatureSensor::refresh()
{
}
