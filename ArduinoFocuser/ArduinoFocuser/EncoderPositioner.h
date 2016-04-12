// EncoderPositioner.h

#ifndef _ENCODERPOSITIONER_h
#define _ENCODERPOSITIONER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Positioner.h"

class EncoderPositioner : public Positioner {
public:
	EncoderPositioner();
	EncoderPositioner(char _pinA, char _pinB, PushButton _resetButton, PushButton _lowLimitButton, PushButton _highLimitButton, PushButton _turboButton);
	EncoderPositioner(char _pinA, char _pinB, int _turboMultiplier, PushButton _resetButton, PushButton _lowLimitButton, PushButton _highLimitButton, PushButton _turboButton);
	EncoderPositioner(char _pinA, char _pinB);
	~EncoderPositioner() override;
	void increment(long _change) override;

private:
	char pinA = 0, pinB = 0;
	void interruptA();
	void interruptB();
	PushButton resetButton, lowLimitButton, highLimitButton, turboButton;
	int turboMultiplier = 10;
};

#endif

