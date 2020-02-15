#include <LiquidCrystal.h>

/*
  Name:		ArduinoFocuser.ino
  Created:	4/12/2016 11:12:14 AM
  Author:	jeff
*/

// the setup function runs once when you press reset or power the board
#include <LCD.h>
#include "StepperMotor.h"
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


LCDDisplay lcd;

StepperMotor stepperMotor;
uint8_t rstPin = 13, stepPin = 10, dirPin = 11, stepSizePin = 12;

// ASCOM/INDI commands
String halt = "HALT", move = "MOVE", isMoving = "MOVING", absolute = "ABSOLUTE",
       position = "POSITION", temperature = "TEMPERATURE", disconnect = "DISCONNECT";
char commandDelimiter = '#';

/* Run before loop.
    Initialize serial communications, all buttons, the encoder and interrupts, the temperature sensor
    lcd, and monitor.
*/
void setup() {
  Serial.begin(115200);
  Serial.println("StupidDog.v1.1");
  reset = PushButton(resetButtonPin, resetLEDPin);
  turbo = PushButton(turboButtonPin, turboLEDPin);

  encoderPositioner = EncoderPositioner(encoderPositionerPinA, encoderPositionerPinB, reset, turbo);
  attachInterrupt(0, interruptA, CHANGE);
  attachInterrupt(1, interruptB, CHANGE);

  temperatureSensor = TemperatureSensor(temperatureSensorPinA);

  lcd = LCDDisplay(&encoderPositioner, temperatureSensor);

  stepperMotor = StepperMotor(rstPin, stepPin, dirPin, stepSizePin, &encoderPositioner);
}

// the loop function runs over and over again until power down or reset
void loop() {
  int8_t suppressTempCounter=0;
  int8_t suppressLCDCounter=0;
  String cmdString, cmd, param;

  if (Serial.available() > 0) {
    cmdString = Serial.readStringUntil(commandDelimiter);

    // Check for separator character
    uint8_t separatorPosition = cmdString.indexOf(":");

    // Parse command if there's a separator
    if (separatorPosition != -1) {
      cmd = cmdString.substring(0, separatorPosition);
      param = cmdString.substring(separatorPosition + 1);
    } else {
      cmd = cmdString;
    }

    if(cmd == move) {
        encoderPositioner.moveRelative(param.toInt());
        Serial.print(encoderPositioner.getPosition()); Serial.println("#");
    } 
    else if(cmd == position){
        Serial.print(encoderPositioner.getPosition()); Serial.println("#");
    }
    else if(cmd == isMoving){
        Serial.println((stepperMotor.isMoving() ? "TRUE#" : "FALSE#"));
    }
    else if(cmd == temperature){
        int temp = temperatureSensor.getTemperature();
        Serial.print(temp); Serial.println("#");
    }
    else if(cmd == halt){
        encoderPositioner.halt();
        Serial.print(encoderPositioner.getPosition()); Serial.println("#");
    }
    else if(cmd == disconnect){
        stepperMotor.disconnect();
        Serial.println("DISCONNECTED#");
    }
  }

  encoderPositioner.refresh();

  if(suppressLCDCounter--<=0){
    lcd.refresh();
    suppressLCDCounter=255;
  }

  stepperMotor.refresh();
}

// Interrupt routines to trigger the encoder
void interruptA() {
  encoderPositioner.interruptA();
}

void interruptB() {
  encoderPositioner.interruptB();
}
