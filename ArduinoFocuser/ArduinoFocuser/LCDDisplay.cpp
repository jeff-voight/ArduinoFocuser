// 
// 
// 

#include "LCDDisplay.h"

LCDDisplay::LCDDisplay()
{
}

LCDDisplay::LCDDisplay(short _addr, short _sdlPin, short _sdaPin, Positioner* _positioner, TemperatureSensor _temperatureSensor):lcd(0x27)
{
  lcd.begin();
	lcd.clear();
	//lcd.noBacklight();
  delay(100);
	lcd.setCursor(0, 0);
	lcd.print(tempLabel);
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
<<<<<<< HEAD
<<<<<<< HEAD


=======
>>>>>>> 6584177ef95c811bfca0f5024842edff6fdf28e3
=======
>>>>>>> 03cdf8017e282394ac3c66f675fc6916d1ac39d8
}

LCDDisplay::~LCDDisplay()
{
	

}

void LCDDisplay::refresh()
{
	int temperature = temperatureSensor.getTemperature();
	long position = positioner->getPosition();
	long change = positioner->getChange();
	lcd.setCursor(4, 0);
	lcd.print(padInt(temperature, 4));
	lcd.setCursor(14, 0);
	lcd.print(padInt(position, 6));
	lcd.setCursor(14, 1);
	lcd.print(padInt(change, 6));
<<<<<<< HEAD
<<<<<<< HEAD
=======
//	lcd.setCursor(4, 3);
//	lcd.print(currentWarning);
>>>>>>> 6584177ef95c811bfca0f5024842edff6fdf28e3
=======
>>>>>>> 03cdf8017e282394ac3c66f675fc6916d1ac39d8
}

String LCDDisplay::padInt(int _theInt, short _size)
{
	String tempString = spaces + _theInt;
	tempString = tempString.substring(tempString.length() - _size);
	return tempString;
}

String LCDDisplay::padDouble(double _theDouble, short _size)
{
	int tempInt = round(_theDouble * 10);
	double tempDouble = 0.0 + tempInt / 10;
	String tempString = spaces + tempDouble;
	tempString = tempString.substring(tempString.length() - _size);
	return tempString;
}
