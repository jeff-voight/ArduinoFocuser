/*
 Name:		ArduinoFocuser.ino
 Created:	4/12/2016 11:12:14 AM
 Author:	jeff
*/

// the setup function runs once when you press reset or power the board

#include "StepperMotor.h"
#include <Wire.h>

#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <LCD.h>
#include "LCDDisplay.h"
#include "TemperatureSensor.h"
#include "ArduinoCircuit.h"
#include "PushButton.h"
#include "EncoderPositioner.h"
#include "Positioner.h"

PushButton reset, lowLimit, highLimit, turbo;
uint8_t resetButtonPin = 4, resetLEDPin = A0, lowLimitButtonPin = 5, lowLimitLEDPin = A1,
	highLimitButtonPin = 6, highLimitLEDPin = A2, turboButtonPin = 7, turboLEDPin = A3;
EncoderPositioner encoderPositioner;
uint8_t encoderPositionerPinA = 2, encoderPositionerPinB = 3;
TemperatureSensor temperatureSensor;
uint8_t temperatureSensorPinA = 8;
uint8_t lcdSdl = 2, lcdSda = 1;
LCDDisplay lcd;
uint8_t lcdAddr = 0x27;
StepperMotor stepperMotor;
uint8_t rstPin = 13, stepPin = 10, dirPin = 11, stepSizePin = 12;
String halt = "HALT", move = "MOVE", isMoving = "MOVING", absolute = "ABSOLUTE", position = "POSITION", temperature="TEMPERATURE"; // ASCOM commands
char commandDelimiter = '#';

void setup() {
	Serial.begin(115200);
	reset = PushButton(resetButtonPin, resetLEDPin);
	lowLimit = PushButton(lowLimitButtonPin, lowLimitLEDPin);
	highLimit = PushButton(highLimitButtonPin, highLimitLEDPin);
	turbo = PushButton(turboButtonPin, turboLEDPin);
	encoderPositioner = EncoderPositioner(encoderPositionerPinA, encoderPositionerPinB, reset, lowLimit, highLimit, turbo);
	temperatureSensor = TemperatureSensor(temperatureSensorPinA);
	lcd = LCDDisplay(lcdAddr, lcdSdl, lcdSda, &encoderPositioner, temperatureSensor);
	stepperMotor = StepperMotor(rstPin, stepPin, dirPin, stepSizePin, &encoderPositioner);
	attachInterrupt(0, interruptA, CHANGE);
	attachInterrupt(1, interruptB, CHANGE);
	
}

// the loop function runs over and over again until power down or reset
void loop() {
	String cmdString, cmd, param;
	if (Serial.available() > 0) {
		cmdString = Serial.readStringUntil(commandDelimiter);
		int separatorPosition = cmdString.indexOf(":");
		if (separatorPosition != -1) {
			cmd = cmdString.substring(0, separatorPosition);
			param = cmdString.substring(separatorPosition+1);
			//Serial.print("CMD: "); Serial.print(cmd); Serial.print(" Param: "); Serial.println(param);
		} else {
			cmd = cmdString;
		}
		if (cmd == move) {
			encoderPositioner.moveRelative(param.toInt());
			Serial.print(encoderPositioner.getPosition()); Serial.println("#");
		} else if (cmd == position) {
			Serial.print(encoderPositioner.getPosition()); Serial.println("#");
		} else if (cmd == isMoving) {
			Serial.println((stepperMotor.isMoving() ? "TRUE#" : "FALSE#"));
		} else if (cmd == temperature) {
			int temp = temperatureSensor.getTemperature();
			Serial.print(temperature); Serial.println("#");
		} else if (cmd == halt) {
			encoderPositioner.halt();
			Serial.print(encoderPositioner.getPosition()); Serial.println("#");
		}
				
	}
	encoderPositioner.refresh();
	temperatureSensor.refresh();
	lcd.refresh();
	stepperMotor.refresh();
}

void interruptA(){
	encoderPositioner.interruptA();
}

void interruptB() {
	encoderPositioner.interruptB();
}