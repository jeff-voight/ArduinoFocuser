// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

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
	uint8_t debounceTime = 30; // 50 milliseconds
	uint8_t defaultBrightness = 128;
};

#endif
