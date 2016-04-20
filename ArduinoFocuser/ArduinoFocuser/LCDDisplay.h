// LCDDisplay.h

#ifndef _LCDDISPLAY_h
#define _LCDDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include <LiquidCrystal_I2C.h>
#include "ArduinoCircuit.h"
#include "TemperatureSensor.h"
#include "Positioner.h"


class LCDDisplay : public ArduinoCircuit {
public:
	LCDDisplay();
	LCDDisplay(uint8_t _addr, uint8_t _sdlPin, uint8_t _sdaPin, Positioner* _positioner, TemperatureSensor _temperatureSensor);
	~LCDDisplay();
	void refresh();

private:
	uint8_t sdlPin=2, sdaPin=1;
	uint8_t addr=0x27;
	LiquidCrystal_I2C lcd;
	Positioner *positioner;
	TemperatureSensor temperatureSensor;
	bool backlight;
	uint8_t Rw = 0, Rs = 4, d4 = 5, d5 = 6, d6 = 7, backlighPin = 3;
	t_backlighPol pol = POSITIVE;
	uint8_t width = 20, height = 4;
	String padInt(int _theInt, uint8_t _size);
	String padDouble(double _theDouble, uint8_t _size);
	String spaces = "                    "; // 20 so far
	String lowLimitWarnMessage = "Low warning", lowLimitMessage = "Low limit", highLimitWarnMessage = "High warning",
		highLimitMessage = "High limit", dewWarning = "Dew Point", noWarning = "No warnings";
	String tempLabel = "TEMP", humiLabel = "HUMI", dewLabel = "DEW",
		posLabel = "POS", chgLabel = "CHG", spdLabel = "SPD", warnLabel = "WARN";
	
	String currentWarning = noWarning;
};

#endif

