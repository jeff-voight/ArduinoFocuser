// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#include "arduino.h"

#include "ArduinoCircuit.h"

class PushButton : public ArduinoCircuit {
public:
	PushButton();
	PushButton(uint8_t _buttonPin, uint8_t _LEDPin);
	~PushButton();
	virtual void refresh();
	bool isPushed();
	bool isHeld();
	bool debounce();
	void setLED(bool _state);

private:
	uint8_t buttonPin = 0, LEDPin = 0;
	bool pushed = false, held=false, lit=false, blink=false;
	long lastButtonPushTime = 0;
	int heldThreshold = 1 * 1000; // 2 Seconds
	int debounceTime = 50; // 50 milliseconds
	int defaultBrightness = 128;
};

#endif

