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
  stepper = AccelStepper(1, _stepPin, _dirPin);
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(30);
  
	pinMode(rstPin, OUTPUT);
	digitalWrite(rstPin, HIGH);
	pinMode(stepSizePin, OUTPUT);
}

StepperMotor::~StepperMotor()
{
}

void StepperMotor::refresh()
{
  stepper.run();
  long currentPosition = stepper.currentPosition();
	change = positioner->getChange();
	if (change != 0) {
		stepper.moveTo(currentPosition+change);
	}

  positioner->setPosition(currentPosition);

}

bool StepperMotor::isMoving()
{
	return stepper.isRunning();
}

bool StepperMotor::disconnect()
{
	digitalWrite(rstPin, LOW);
	return true;
}
