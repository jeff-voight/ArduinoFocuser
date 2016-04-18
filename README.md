# ArduinoFocuser
My homemade Arduino Focuser

This project uses the following components:

Two (2) 3cm x 7cm perfboards
Four (4) LEDs
Four (4) momentary-on pushbuttons
Four (4) 220ohm resistors (any value in this order of magnitude should be fine)
Four (4) 22kohm resistors (any value in this order of magnitude should be fine as long as they're all the same.)
One (1) 47uF capacitor
One (1) DRV8825 Stepper Motor Driver (you MUST set the current limit screw! These do not come factory-set!)
One (1) Rotary encoder
One (1) Sainsmart 20x4 I2C LCD
One (1) DHT11 Temperature and Humidity Sensor
One (1) NEMA-17 27:1 geared stepper (5400 steps per revolution)
One (1) Arduino UNOr3
One (1) case of your choosing (plans for printing a sloppy case are included in the project)
One (1) Motor mount (plans for printing a mount that fits a Meade LX70 R5 are included in the project)
One (1) coupler (I went with a 4mm x 6mm flexible coupler and drilled it to fit my shafts)
One (1) 12VDC 2A power supply (wall-wart. You're just plugging it in to the Arduino UNOr3)
Solder, wires, old-school hard drive power connectors (4 pins and you probably have eleven of them in a drawer somewhere)
M2 5mm screws, M3 5mm screws, #6 1/2" countersunk woodscrews (smaller is better but, I couldn't find them at Home Depot)
One mile long USB-A to USB-2 cable (or whatever the distance is from your laptop USB hub to where the focuser box will sit plus tripping slack)

Things you'll want to change in the code:
My telescope focuser knob turns 5.75 times to go from end to end and moves some 13cm (or was it 23?). EncoderPositioner.h and StepperMotor.h are important.
For now, there may very-well be hardcoded values in the cpp files. I highly recommend you walk through them before applying bizarre amounts of
torque to your telescope focuser rod.
For the love of all that is good and sane, come up with a better name/splash screen for the LCD.

To do:
I want to add a limit switch to the motor end of the focus tube to detect the zero point. I haven't figured out how I want to impliment this. Maybe have the
focuser close on startup and then return to where it was.

I also want to add a few strips of nichrome wire to the lens-ends of the scope, finder, guider and 
periodically pump some electricity if the dewpoint gets within 5 degrees of the temperature but, I'm pretty sure I'm out of pins unless I can use the RX/TX
pins without interfering with the ASCOM serial.

Build a better case. For whatever reason, I can't get mine to close all the way and I'm pretty certain that I'm generating enough heat inside the box to affect
the DHT11 mounted on the side.
