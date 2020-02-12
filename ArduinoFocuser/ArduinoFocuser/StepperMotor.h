#include <AccelStepper.h>

// StepperMotor.h

#ifndef _STEPPERMOTOR_h
#define _STEPPERMOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ArduinoCircuit.h"
#include "Positioner.h"

#define stepsPerRevolution 5400

class StepperMotor: public ArduinoCircuit {
public:
	StepperMotor();
	StepperMotor(uint8_t _rstPin, uint8_t _stepPin, uint8_t _dirPin, uint8_t _stepSizePin, Positioner* _positioner);
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
