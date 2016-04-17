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
	change = positioner->getChange();
	if (change == 0) {
		digitalWrite(stepPin, 0); // in case halt was called
		moving = false;
	}
	long moved = getSteps(); // How many steps did we take last cycle?
	//Serial.print("We moved "); Serial.print(moved); Serial.println(" steps in the last cycle.");
	positioner->adjustMoved(moved); // update the positioner so it can display it
	
	long steps=step(); // Tell the motor whether to move, move slow, or stop
	positioner->adjustMoved(steps); // if slow stepping, this tells us how many steps cycled
}

long StepperMotor::getSteps() {
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

long StepperMotor::step()
{
	int dirMultiplier = 1;
	long stepsRemaining = abs(change);
	if (change == 0) {
		digitalWrite(stepPin, 0); // halt if something needs it.
		moving = false;
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
		
		int lesserVal = (stepsRemaining < 10?stepsRemaining:10);
		analogWrite(stepPin, 0); // Stop the motor if it's moving
		digitalWrite(stepSizePin, HIGH); // Go halfstep for final adjustment. Probably just for show.
		for (int i = 0; i < lesserVal && change!=0; i++) {
			digitalWrite(stepPin, HIGH);
			delay(1);
			digitalWrite(stepPin, LOW);
			delay(1);
		}
		moving = false;
		return lesserVal*dirMultiplier;
	} else {
		digitalWrite(stepSizePin, LOW);
		ms = millis();
		analogWrite(stepPin, 127);
		moving = true;
	}
	return 0;
}
