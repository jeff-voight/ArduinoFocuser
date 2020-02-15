
// LCDDisplay.h

#ifndef _LCDDISPLAY_h
#define _LCDDISPLAY_h
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "TemperatureSensor.h"
#include "Positioner.h"


class LCDDisplay {
public:
	LCDDisplay();
	LCDDisplay(Positioner* _positioner, TemperatureSensor _temperatureSensor);
	~LCDDisplay();
	void refresh();

private:
	short sdlPin=2, sdaPin=1;
	short addr=0x27;
	Positioner *positioner;
	TemperatureSensor temperatureSensor;
	bool backlight;
	uint8_t pol = HIGH;
	uint8_t width = 20, height = 4;
  LiquidCrystal_I2C lcd=LiquidCrystal_I2C(addr,width,height);
	String padInt(uint8_t _theInt, uint8_t _size);
	String padDouble(double _theDouble, uint8_t _size);
	String spaces = "                    "; // 20 so far

	String tempLabel = "TEMP", posLabel = "POS", chgLabel = "CHG", spdLabel = "SPD", warnLabel = "WARN";
	
};

#endif
