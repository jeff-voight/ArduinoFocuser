// ArduinoCircuit.h

#ifndef _ARDUINOCIRCUIT_h
#define _ARDUINOCIRCUIT_h

class ArduinoCircuit {
public:
	ArduinoCircuit();
	virtual ~ArduinoCircuit();
	virtual void refresh() = 0;
};

#endif
