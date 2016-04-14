// 
// 
// 

#include "LCDDisplay.h"

LCDDisplay::LCDDisplay():lcd(0x27)
{
}

LCDDisplay::LCDDisplay(uint8_t _addr, uint8_t _sdlPin, uint8_t _sdaPin, Positioner* _positioner, TemperatureSensor _temperatureSensor):lcd(0x27)
{
	addr = _addr;
	sdlPin = _sdlPin;
	sdaPin = _sdaPin;
	lcd = LiquidCrystal_I2C(addr, sdlPin, sdaPin, Rw, Rs, d4, d5, d6, backlighPin, pol);
	lcd.begin(width, height);
	lcd.clear();
	lcd.setBacklight(HIGH);
	lcd.setCursor(0, 0);
	lcd.print("ArduinoFocus v:0.1");
	lcd.setCursor(0, 1);
	lcd.print("By Jeffrey Voight");
	delay(3000);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(tempLabel);
	lcd.setCursor(0, 1);
	lcd.print(humiLabel);
	lcd.setCursor(0, 2);
	lcd.print(dewLabel);
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
	int humidity = temperatureSensor.getHumidity();
	int dewPoint = temperatureSensor.getDewPoint();
	long position = positioner->getPosition();
	long change = positioner->getChange();
	lcd.setCursor(4, 0);
	lcd.print(padInt(temperature, 4));
	lcd.setCursor(4, 1);
	lcd.print(padInt(humidity, 4));
	lcd.setCursor(4, 2);
	lcd.print(padInt(dewPoint, 4));
	lcd.setCursor(14, 0);
	lcd.print(padInt(position, 6));
	lcd.setCursor(14, 1);
	lcd.print(padInt(change, 6));
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
