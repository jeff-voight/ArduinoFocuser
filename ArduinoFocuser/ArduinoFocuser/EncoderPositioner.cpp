// 
// 
// 

#include "EncoderPositioner.h"

EncoderPositioner::EncoderPositioner()
{
	pinA = 0;
	pinB = 0;
	resetButton = 0;
	lowLimitButton = 0;
	highLimitButton = 0;
	turboButton = 0;
}

EncoderPositioner::EncoderPositioner(char _pinA, char _pinB, PushButton _resetButton, PushButton _lowLimitButton, PushButton _highLimitButton, PushButton _turboButton)
{
	pinA = _pinA;
	pinB = _pinB;
	resetButton = _resetButton;
	lowLimitButton = _lowLimitButton;
	highLimitButton = _highLimitButton;
	turboButton = _turboButton;
}

EncoderPositioner::EncoderPositioner(char _pinA, char _pinB, int _turboMultiplier, PushButton _resetButton, PushButton _lowLimitButton, PushButton _highLimitButton, PushButton _turboButton)
{
	pinA = _pinA;
	pinB = _pinB;
	turboMultiplier = _turboMultiplier;
	resetButton = _resetButton;
	lowLimitButton = _lowLimitButton;
	highLimitButton = _highLimitButton;
	turboButton = _turboButton;
}

EncoderPositioner::EncoderPositioner(char _pinA, char _pinB)
{
	pinA = _pinA;
	pinB = _pinB;
	resetButton = 0;
	lowLimitButton = 0;
	highLimitButton = 0;
	turboButton = 0;
}

EncoderPositioner::~EncoderPositioner()
{
	delete resetButton;
	delete lowLimitButton;
	delete highLimitButton;
	delete turboButton;
}

void EncoderPositioner::increment(long _change)
{
	if (turboButton != 0) {
		addChange(_change*turboMultiplier);
	} else {
		addChange(_change);
	}
}

void EncoderPositioner::refresh() {

}

void EncoderPositioner::interruptA()
{
	increment(change);
}

void EncoderPositioner::interruptB()
{
	increment(change);
}
