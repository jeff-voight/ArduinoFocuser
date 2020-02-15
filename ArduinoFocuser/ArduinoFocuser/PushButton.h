// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h
#include "Arduino.h"

class PushButton {
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
	uint8_t debounceTime = 30; // 50 milliseconds
	uint8_t defaultBrightness = 128;
};

#endif
