/*
 Name:		ArduinoFocuser.ino
 Created:	4/12/2016 11:12:14 AM
 Author:	jeff
*/

// the setup function runs once when you press reset or power the board




#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <I2CIO.h>
#include <FastIO.h>

#include "StepperMotor.h"
#include <Wire.h>


#include "LCDDisplay.h"
#include "TemperatureSensor.h"
#include "ArduinoCircuit.h"
#include "PushButton.h"
#include "EncoderPositioner.h"
#include "Positioner.h"

#define resetButtonPin  4
#define resetLEDPin  A0
#define lowLimitButtonPin 5
#define lowLimitLEDPin A1
#define	highLimitButtonPin 6
#define highLimitLEDPin A2
#define turboButtonPin 7
#define turboLEDPin A3
#define encoderPositionerPinA  2
#define encoderPositionerPinB 3
#define temperatureSensorPinA 8
#define lcdSdl  2
#define lcdSda  1
#define lcdAddr 0x27
#define RSTPIN 13
#define STEPPIN 10
#define DIRPIN 11
#define STEPSIZEPIN 12

PushButton reset, lowLimit, highLimit, turbo;
EncoderPositioner encoderPositioner;
LCDDisplay lcd;
StepperMotor stepperMotor;
TemperatureSensor temperatureSensor;

String halt = "HALT", move = "MOVE", isMoving = "MOVING", absolute = "ABSOLUTE", position = "POSITION", temperature="TEMPERATURE"; // ASCOM commands
char commandDelimiter = '#';

void setup() {
	Serial.begin(115200);
	Serial.println("Connected.");
	Serial.flush();
	reset = PushButton(resetButtonPin, resetLEDPin);
	lowLimit = PushButton(lowLimitButtonPin, lowLimitLEDPin);
	highLimit = PushButton(highLimitButtonPin, highLimitLEDPin);
	turbo = PushButton(turboButtonPin, turboLEDPin);
	encoderPositioner = EncoderPositioner(encoderPositionerPinA, encoderPositionerPinB, reset, lowLimit, highLimit, turbo);
	temperatureSensor = TemperatureSensor(temperatureSensorPinA);
	lcd = LCDDisplay(lcdAddr, lcdSdl, lcdSda, &encoderPositioner, temperatureSensor);
	stepperMotor = StepperMotor(RSTPIN, STEPPIN, DIRPIN, STEPSIZEPIN, &encoderPositioner);
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
			encoderPositioner.moveAbsolute(param.toInt());
			//encoderPositioner.moveRelative(param.toInt());
			Serial.print(encoderPositioner.getPosition()); Serial.println("#");
		} else if (cmd == position) {
			Serial.print(encoderPositioner.getPosition()); Serial.println("#");
		} else if (cmd == isMoving) {
			Serial.println((stepperMotor.isMoving() ? "TRUE#" : "FALSE#"));
		} else if (cmd == temperature) {
			int temp = temperatureSensor.getTemperature();
			Serial.print(temp); Serial.println("#");
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