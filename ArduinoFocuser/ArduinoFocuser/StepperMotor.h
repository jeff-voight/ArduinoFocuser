// StepperMotor.h

#ifndef _STEPPERMOTOR_h
#define _STEPPERMOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ArduinoCircuit.h"
#include "Positioner.h"

class StepperMotor: public ArduinoCircuit {
public:
	StepperMotor();
	StepperMotor(uint8_t _rstPin, uint8_t _stepPin, uint8_t _dirPin, uint8_t _stepSizePin, Positioner* _positioner);
	~StepperMotor();
	void refresh();
	bool isMoving();
	bool disconnect();

private:
	uint16_t stepsPerRevolution = 5400, processorStepsPerSecond = 490;
	double stepsPerMS = 0.0 + processorStepsPerSecond / 1000.0;
	long slowStepsThreshold = 500;
	uint8_t rstPin, stepPin, dirPin, stepSizePin;
	Positioner* positioner;
	long change;
	long ms = millis();
	bool moving = false;
	long step();
	long getSteps();

};
#endif

