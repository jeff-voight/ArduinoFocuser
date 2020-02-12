// 
// 
// 

#include "PushButton.h"

PushButton::PushButton()
{
	buttonPin = -1;
	LEDPin = -1;
}

PushButton::PushButton(short _buttonPin, short _LEDPin)
{
	buttonPin = _buttonPin;
	LEDPin = _LEDPin;
	pinMode(buttonPin, INPUT);
	pinMode(LEDPin, OUTPUT);
}

PushButton::~PushButton()
{
}

void PushButton::refresh()
{
	debounce();
	setLED(pushed);
}

bool PushButton::isPushed()
{
	refresh();
	return pushed;
}

bool PushButton::isHeld()
{
	return held;
}

bool PushButton::debounce()
{
	if (buttonPin == -1) {
		return false;
	}
	int reading = digitalRead(buttonPin);
	delay(debounceTime);
	int secondReading = digitalRead(buttonPin);
	if (reading != secondReading || reading==LOW) {
		pushed = false;
		held = false;
		lastButtonPushTime = 0;
		return false;
	}	
	pushed = true;	
	if (lastButtonPushTime > 0) {
		long holdTime = millis() - lastButtonPushTime;
		if (holdTime > heldThreshold) {
			held = true;
		}
	} else {
		lastButtonPushTime = millis();
	}	 
	return pushed;
}

void PushButton::setLED(bool _state)
{
	if (LEDPin == -1) {
		return;
	}
	lit = _state;
	if (lit) {
		analogWrite(LEDPin, defaultBrightness);
	} else {
		analogWrite(LEDPin, 0);
	}
}
