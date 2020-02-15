#include <AccelStepper.h>

// StepperMotor.h

#ifndef _STEPPERMOTOR_h
#define _STEPPERMOTOR_h

#include "Positioner.h"

#define stepsPerRevolution 5400

class StepperMotor {
public:
	StepperMotor();
	StepperMotor(short _rstPin, short _stepPin, short _dirPin, short _stepSizePin, Positioner* _positioner);
	~StepperMotor();
	void refresh();
	bool isMoving();
	bool disconnect();
  AccelStepper stepper;

private:
	uint8_t rstPin, stepPin, dirPin, stepSizePin;
	Positioner* positioner;
	long change;
	long ms = millis();
	bool moving = false;

};
#endif
