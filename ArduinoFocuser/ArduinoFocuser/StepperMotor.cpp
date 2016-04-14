// 
// 
// 

#include "StepperMotor.h"

StepperMotor::StepperMotor()
{
}

StepperMotor::StepperMotor(uint8_t _rstPin, uint8_t _stepPin, uint8_t _dirPin, uint8_t _stepSizePin, Positioner * _positioner)
{
	rstPin = _rstPin;
	stepPin = _stepPin;
	dirPin = _dirPin;
	stepSizePin = _stepSizePin;
	positioner = _positioner;
	pinMode(rstPin, OUTPUT);
	digitalWrite(rstPin, HIGH);
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
	pinMode(stepSizePin, OUTPUT);
}

StepperMotor::~StepperMotor()
{
}

void StepperMotor::refresh()
{
	long moved = getSteps();
	positioner->adjustMoved(moved);
	change = positioner->getChange();
	long steps=step();
	positioner->adjustMoved(steps);
}

long StepperMotor::getSteps() {
	int multiplier = 1;
	if (!moving) {
		return 0;
	}
	if (change < 0) {
		multiplier = -1;
	}
	long now = millis();
	long diff = now - ms;
	return (long)(stepsPerMS*diff)*multiplier;

}

long StepperMotor::step()
{
	int dirMultiplier = 1;
	long stepsRemaining = abs(change);
	if (change > 0) {
		digitalWrite(dirPin, HIGH);
		dirMultiplier = 1;
	} else {
		digitalWrite(dirPin, LOW); 
		dirMultiplier = -1;
	}
	if (stepsRemaining < slowStepsThreshold) {
		moving = false;
		int lesserVal = (stepsRemaining < 10?stepsRemaining:10);
		analogWrite(stepPin, 0); // Stop the motor if it's moving
		digitalWrite(stepSizePin, HIGH); // Go halfstep for final adjustment. Probably just for show.
		for (int i = 0; i < lesserVal; i++) {
			digitalWrite(stepPin, HIGH);
			delay(5);
			digitalWrite(stepPin, LOW);
			delay(5);
		}
		return lesserVal*dirMultiplier;
	} else {
		digitalWrite(stepSizePin, LOW);
		ms = millis();
		analogWrite(stepPin, 127);
		moving = true;
	}
	return 0;
}
