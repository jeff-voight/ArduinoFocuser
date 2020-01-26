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

#define stepsPerRevolution 5400
#define processorStepsPerSecond 490
#define slowStepsThreshold 500

class StepperMotor: public ArduinoCircuit {
public:
	StepperMotor();
	StepperMotor(uint8_t _rstPin, uint8_t _stepPin, uint8_t _dirPin, uint8_t _stepSizePin, Positioner* _positioner);
	~StepperMotor();
	void refresh();
	bool isMoving();

private:

	double stepsPerMS = 0.0 + processorStepsPerSecond / 1000.0;
	uint8_t rstPin, stepPin, dirPin, stepSizePin;
	Positioner* positioner;
	long change;
	long ms = millis();
	bool moving = false;
	long step();
	long getSteps();
};
#endif

