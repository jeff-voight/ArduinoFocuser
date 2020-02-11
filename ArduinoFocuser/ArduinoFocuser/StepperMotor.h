// StepperMotor.h

#ifndef _STEPPERMOTOR_h
#define _STEPPERMOTOR_h

#include "ArduinoCircuit.h"
#include "Positioner.h"

class StepperMotor: public ArduinoCircuit {
public:
	StepperMotor();
	StepperMotor(short _rstPin, short _stepPin, short _dirPin, short _stepSizePin, Positioner* _positioner);
	~StepperMotor();
	void refresh();
	bool isMoving();
	bool disconnect();

private:
	uint16_t stepsPerRevolution = 5400, processorStepsPerSecond = 490;
	double stepsPerMS = 0.0 + processorStepsPerSecond / 1000.0;
	long slowStepsThreshold = 500;
	short rstPin, stepPin, dirPin, stepSizePin;
	Positioner* positioner;
	long change;
	long ms = millis();
	bool moving = false;
	long step();
	long getSteps();

};
#endif
