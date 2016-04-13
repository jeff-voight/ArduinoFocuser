// 
// 
// 

#include "LCDDisplay.h"

LCDDisplay::LCDDisplay():lcd(0x27)
{
}

LCDDisplay::LCDDisplay(uint8_t _addr, uint8_t _sdlPin, uint8_t _sdaPin):lcd(0x27)
{
	addr = _addr;
	sdlPin = _sdlPin;
	sdaPin = _sdaPin;
	lcd = LiquidCrystal_I2C(addr, sdlPin, sdaPin, Rw, Rs, d4, d5, d6, backlighPin, pol);
	lcd.begin(width, height);
	lcd.clear();
	lcd.setBacklight(HIGH);

}

LCDDisplay::~LCDDisplay()
{
}

void LCDDisplay::refresh()
{
	lcd.print("This!");
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
