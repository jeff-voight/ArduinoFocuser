// 
// 
// 

#include "StepperMotor.h"

StepperMotor::StepperMotor()
{
}

StepperMotor::StepperMotor(short _rstPin, short _stepPin, short _dirPin, short _stepSizePin, Positioner * _positioner)
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
	change = positioner->getChange();
	if (change == 0) {
		digitalWrite(stepPin, LOW); // in case halt was called
		moving = false;
	}
	long moved = getStepsMovedLastCycle(); // How many steps did we take last cycle?
	//Serial.print("We moved "); Serial.print(moved); Serial.println(" steps in the last cycle.");
	positioner->adjustMoved(moved); // update the positioner so it can display it
	
	long steps=move(); // Tell the motor whether to move, move slow, or stop
	positioner->adjustMoved(steps); // if slow stepping, this tells us how many steps cycled
}

bool StepperMotor::isMoving()
{
	return moving;
}

bool StepperMotor::disconnect()
{
	digitalWrite(rstPin, LOW);
	return true;
}

long StepperMotor::getStepsMovedLastCycle() {
	int multiplier = 2; // 2 because these are whole steps as opposed to half steps near the ends of the travel
	if (!moving||abs(change)<slowStepsThreshold) {
		return 0;
	}
	if (change < 0) {
		multiplier = -2;
	}
	long now = millis();
	long diff = now - ms;
	return (long)(stepsPerMS*diff)*multiplier;

}

long StepperMotor::move()
{
	uint8_t dirMultiplier = 1;
	long stepsRemaining = abs(change);
	if (change == 0) {
		digitalWrite(stepPin, 0); // halt if something needs it.
		moving = false;
		return 0;
	}
	if (change > 0) {
		digitalWrite(dirPin, HIGH);
		dirMultiplier = 1;
	} else {
		digitalWrite(dirPin, LOW); 
		dirMultiplier = -1;
	}
	//Serial.print("Steps remaining: "); Serial.println(stepsRemaining);
	if (stepsRemaining < slowStepsThreshold) {
		digitalWrite(stepSizePin, HIGH); // Halfstep mode
		long timeRemaining = stepsRemaining*2 / stepsPerMS;
		analogWrite(stepPin, 127);
		delay(timeRemaining); // Take advantage of the PWM on the step pin to perform the stepping for a short period
		digitalWrite(stepPin, 0);
		moving = false;
		return stepsRemaining*dirMultiplier;
	} else {
		digitalWrite(stepSizePin, LOW); // Fullstep mode
		ms = millis();
		analogWrite(stepPin, 127);
		moving = true;
	}
	return 0;
}
