// 
// 
// 

#include "LCDDisplay.h"

LCDDisplay::LCDDisplay()
{
}

LCDDisplay::LCDDisplay(Positioner* _positioner, TemperatureSensor _temperatureSensor)
{
  lcd.begin();
	lcd.clear();
	lcd.noBacklight();
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(tempLabel);
	//lcd.setCursor(0, 1);
	//lcd.print(humiLabel);
	//lcd.setCursor(0, 2);
	//lcd.print(dewLabel);
	lcd.setCursor(0, 3);
	lcd.print(warnLabel);
	lcd.setCursor(10, 0);
	lcd.print(posLabel);
	lcd.setCursor(10, 1);
	lcd.print(chgLabel);
	lcd.setCursor(10, 2);
	lcd.print(spdLabel);
	positioner = _positioner;
	temperatureSensor = _temperatureSensor;
}

LCDDisplay::~LCDDisplay()
{
	

}

void LCDDisplay::refresh()
{
	
	int temperature = temperatureSensor.getTemperature();
	//uint8_t humidity = temperatureSensor.getHumidity();
	//int dewPoint = temperatureSensor.getDewPoint();
	long position = positioner->getPosition();
	long change = positioner->getChange();
	
	lcd.setCursor(4, 0);
	lcd.print(padInt(temperature, 4));
	//lcd.setCursor(4, 1);
	//lcd.print(padInt(humidity, 4));
	//lcd.setCursor(4, 2);
	//lcd.print(padInt(dewPoint, 4));
	lcd.setCursor(14, 0);
	lcd.print(padInt(position, 6));
	lcd.setCursor(14, 1);
	lcd.print(padInt(change, 6));
//	lcd.setCursor(4, 3);
//	lcd.print(currentWarning);
}

String LCDDisplay::padInt(int _theInt, uint8_t _size)
{
	String tempString = spaces + _theInt;
	tempString = tempString.substring(tempString.length() - _size);
	return tempString;
}

String LCDDisplay::padDouble(double _theDouble, uint8_t _size)
{
	int tempInt = round(_theDouble * 10);
	double tempDouble = 0.0 + tempInt / 10;
	String tempString = spaces + tempDouble;
	tempString = tempString.substring(tempString.length() - _size);
	return tempString;
}
