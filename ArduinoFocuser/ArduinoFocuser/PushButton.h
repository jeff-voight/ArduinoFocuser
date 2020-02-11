// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#include "ArduinoCircuit.h"

class PushButton : public ArduinoCircuit {
public:
	PushButton();
	PushButton(short _buttonPin, short _LEDPin);
	~PushButton();
	virtual void refresh();
	bool isPushed();
	bool isHeld();
	bool debounce();
	void setLED(bool _state);

private:
	short buttonPin = 0, LEDPin = 0;
	bool pushed = false, held=false, lit=false, blink=false;
	long lastButtonPushTime = 0;
	int heldThreshold = 1 * 1000; // 2 Seconds
	int debounceTime = 50; // 50 milliseconds
	int defaultBrightness = 128;
};

#endif
