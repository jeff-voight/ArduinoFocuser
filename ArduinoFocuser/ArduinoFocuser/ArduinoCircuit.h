// ArduinoCircuit.h

#ifndef _ARDUINOCIRCUIT_h
#define _ARDUINOCIRCUIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ArduinoCircuit {
public:
	ArduinoCircuit();
	virtual ~ArduinoCircuit();
	virtual void refresh() = 0;
};

#endif

