// EncoderPositioner.h

#ifndef _ENCODERPOSITIONER_h
#define _ENCODERPOSITIONER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Positioner.h"
#include "PushButton.h"

class EncoderPositioner : public Positioner {
public:
	EncoderPositioner();
	EncoderPositioner(char _pinA, char _pinB, PushButton _resetButton, PushButton _lowLimitButton, PushButton _highLimitButton, PushButton _turboButton);
	EncoderPositioner(char _pinA, char _pinB, int _turboMultiplier, PushButton _resetButton, PushButton _lowLimitButton, PushButton _highLimitButton, PushButton _turboButton);
	EncoderPositioner(char _pinA, char _pinB);
	~EncoderPositioner();
	virtual void increment(long _change) override;
	virtual void refresh() ;
	void interruptA();
	void interruptB();

private:
	uint8_t pinA = 0, pinB = 0;
	volatile int oldA = LOW;
    volatile int oldB = LOW;
	volatile unsigned long lastMicros = micros();
	long debouncingTime = 15;
	PushButton resetButton, lowLimitButton, highLimitButton, turboButton;
	int turboMultiplier = 10;
};

#endif
