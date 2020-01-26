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
	//DHT.attach(pinA);
	DHT.read11(pinA);
}

TemperatureSensor::~TemperatureSensor()
{
}

double TemperatureSensor::getTemperature()
{
	DHT.read11(pinA);
	return DHT.temperature;
}

double TemperatureSensor::getHumidity()
{
	DHT.read11(pinA);
	return DHT.humidity;
}

double TemperatureSensor::getDewPoint()
{
	return DHT.temperature - ((100- DHT.humidity)/5);
}

void TemperatureSensor::refresh()
{
	DHT.read11(pinA);
}
