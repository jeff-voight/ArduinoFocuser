#include <Wire.h>
#include <LiquidCrystal_I2C.h>


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
        //dht11 = DHT(pinA, DHTTYPE);
	dht11.begin();
	dht11.readTemperature();
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
	dht11.read();
}
