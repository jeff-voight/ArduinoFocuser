// StepperMotor.h

#ifndef _STEPPERMOTOR_h
#define _STEPPERMOTOR_h

#include "ArduinoCircuit.h"
#include "Positioner.h"

#define stepsPerRevolution 5400
#define processorStepsPerSecond 490
#define slowStepsThreshold 500

class StepperMotor: public ArduinoCircuit {
public:
	StepperMotor();
	StepperMotor(short _rstPin, short _stepPin, short _dirPin, short _stepSizePin, Positioner* _positioner);
	~StepperMotor();
	void refresh();
	bool isMoving();
	bool disconnect();

private:

	double stepsPerMS = 0.0 + processorStepsPerSecond / 1000.0;
	long slowStepsThreshold = 500;
	short rstPin, stepPin, dirPin, stepSizePin;
	Positioner* positioner;
	long change;
	long ms = millis();
	bool moving = false;
	long move();
	long getStepsMovedLastCycle();
};
#endif
