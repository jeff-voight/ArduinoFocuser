// 
// 
// 

#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
{
}

TemperatureSensor::TemperatureSensor(char _pinA)
{
	pinA = _pinA;
	DHT.attach(pinA);
	DHT.read();
}

TemperatureSensor::~TemperatureSensor()
{
}

double TemperatureSensor::getTemperature()
{
	DHT.read();
	return DHT.celcius();
}

double TemperatureSensor::getHumidity()
{
	DHT.read();
	return DHT.humidity;
}

double TemperatureSensor::getDewPoint()
{
	return DHT.dewPoint();
}

void TemperatureSensor::refresh()
{
	DHT.read();
}
