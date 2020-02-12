// EncoderPositioner.h

#ifndef _ENCODERPOSITIONER_h
#define _ENCODERPOSITIONER_h

#include "Positioner.h"
#include "PushButton.h"

class EncoderPositioner : public Positioner {
public:
	EncoderPositioner();
	EncoderPositioner(char _pinA, char _pinB, PushButton _resetButton, PushButton _turboButton);
	EncoderPositioner(char _pinA, char _pinB);
	~EncoderPositioner();
	virtual void increment(long _change) override;
	virtual void refresh() ;
	void interruptA();
	void interruptB();

private:
<<<<<<< HEAD
	uint8_t pinA = 0, pinB = 0;
<<<<<<< HEAD
=======
	short pinA = 0, pinB = 0;
>>>>>>> 03cdf8017e282394ac3c66f675fc6916d1ac39d8
	volatile int oldA = LOW;
    volatile int oldB = LOW;
	volatile long lastMicros = micros();
	long debouncingTime = 15;
<<<<<<< HEAD
=======
	volatile uint8_t oldA = LOW;
  volatile uint8_t oldB = LOW;
	volatile unsigned long lastMicros = micros();
	uint8_t debouncingTime = 15;
>>>>>>> 6584177ef95c811bfca0f5024842edff6fdf28e3
=======
>>>>>>> 03cdf8017e282394ac3c66f675fc6916d1ac39d8
	PushButton resetButton, lowLimitButton, highLimitButton, turboButton;
	uint8_t turboMultiplier = 100;
};

#endif
