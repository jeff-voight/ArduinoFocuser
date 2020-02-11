// LCDDisplay.h

#ifndef _LCDDISPLAY_h
#define _LCDDISPLAY_h



//#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ArduinoCircuit.h"
#include "TemperatureSensor.h"
#include "Positioner.h"


class LCDDisplay : public ArduinoCircuit {
public:
	LCDDisplay();
	LCDDisplay(short _addr, short _sdlPin, short _sdaPin, Positioner* _positioner, TemperatureSensor _temperatureSensor);
	~LCDDisplay();
	void refresh();

private:
	short sdlPin=2, sdaPin=1;
	short addr=0x27;
	LiquidCrystal_I2C lcd;
	Positioner *positioner;
	TemperatureSensor temperatureSensor;
	bool backlight;
	short Rw = 0, Rs = 4, d4 = 5, d5 = 6, d6 = 7, backlighPin = 3;
	t_backlighPol pol = POSITIVE;
	short width = 20, height = 4;
	String padInt(int _theInt, short _size);
	String padDouble(double _theDouble, short _size);
	String spaces = "                    "; // 20 so far
	String tempLabel = "Temp:", humiLabel = "Humi:", dewLabel = "Dew:",
		posLabel = "Pos:", chgLabel = "Chg:", spdLabel = "Spd:", warnLabel = "Warn:";
	String lowLimitWarnMessage = "Low warning", lowLimitMessage = "Low limit", highLimitWarnMessage = "High warning",
		highLimitMessage = "High limit", dewWarning = "Dew Point", noWarning="No warnings";
	String currentWarning = noWarning;
};

#endif
