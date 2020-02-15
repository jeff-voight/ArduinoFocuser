# ArduinoFocuser
My homemade Arduino Focuser

### Parts List
|ID				|#	|Name					|Type								|Module										|Description|
|A1				|1	|Arduino_UNO_R3			|MCU_Module:Arduino_UNO_R3			|Module:Arduino_UNO_R3						|Arduino UNO Microcontroller Module, release 3|
|C1, C2, C3		|3	|.01uF					|Device:C							|Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm	|Unpolarized capacitor|
|DRV1			|1	|Pololu_Breakout_DRV8825|Driver_Motor:Pololu_Breakout_DRV8825|Module:Pololu_Breakout-16_15.2x20.3mm		|Pololu Breakout Board, Stepper Driver DRV8825|
|Motor1			|1	|Stepper_Motor_bipolar	|Motor:Stepper_Motor_bipolar		|TerminalBlock:TerminalBlock_bornier-4_P5.08mm|4-wire bipolar stepper motor|
|R1, R2, R3, R4	|4	|10k					|Device:R							|Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal|Resistor|
|SW1			|1	|Rotary_Encoder_Switch	|Device:Rotary_Encoder_Switch		|Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm|Rotary encoder, dual channel, incremental quadrate outputs, with switch|
|U1				|1	|DHT11					|Sensor:DHT11						|Sensor:Aosong_DHT11_5.5x12.0_P2.54mm		|Temperature and humidity module|
|U2				|1	|SN74HC14N				|dk_Logic-Gates-and-Inverters:SN74HC14N|digikey-footprints:DIP-14_W3mm			|IC INVERTER SCHMITT 6CH 14DIP|


* One (1) case of your choosing (plans for printing a sloppy case are included in the project)
* One (1) Motor mount (PDF somehwere around here for a 18ga steel bracket you can drill and bend yourself)
* One (1) coupler (I went with a 4mm x 6mm flexible coupler and drilled it to fit my shafts)
* One (1) 12VDC 2A power supply (wall-wart. You're just plugging it in to the Arduino UNOr3)
* Solder, wires, 4 pin connectors for as many scopes as you have.
* One long USB-A to USB-2 cable (or whatever the distance is from your laptop USB hub to where the focuser box will sit plus tripping slack)


# Things you'll want to change in the code:
My telescope focuser knob turns 5.75 times to go from end to end and moves some 13cm (or was it 23?). EncoderPositioner.h and StepperMotor.h are important.

For now, there may very-well be hardcoded values in the cpp files. I highly recommend you walk through them before applying bizarre amounts of
torque to your telescope focuser rod.

# To do:
* I want to add a limit switch to the motor end of the focus tube to detect the zero point. I haven't figured out how I want to impliment this. Maybe have the
focuser rack all the way closed on startup and then return to where it was. The problem I have with this is the people who have more than one telescope and 
maybe get the wiring wrong, causing their scope to rack focus out until it runs out of travel space and stalls the motor while seeking for the limit switch.

* Build a better case. For whatever reason, I can't get mine to close all the way and I'm pretty certain that I'm generating enough heat inside the box to affect
the DHT11 mounted on the side.

* Add links to a digikey BOM to order overthing.
