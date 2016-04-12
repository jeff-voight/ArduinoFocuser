// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PushButton : public ArduinoCircuit {
public:
	PushButton();
	PushButton(char _buttonPin, char _LEDPin);
	~PushButton() override;
	void refresh() override;

private:
	char buttonPin = 0, LEDPin = 0;
};

#endif

