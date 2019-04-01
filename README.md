# ECE387-Remote Control Assignmment

## Video Demonstration Link
https://youtu.be/R5WknhNOhNs

## Breadboard Schematic
![Breadboard Schematic](/RemoteControl.png)

## Library GitHub Reference
https://github.com/z3t0/Arduino-IRremote

## Schematic (Uses full Arduino instead of just CPU)
![Schematic](/RemoteControl_schem.png)

## Overview
Using a user built library for IR code transmission, a simulation of a remote control was built using an Arduino. The source code for this IR library was edited to allow for easy viewing of the data transmission using an LED (no IR light of my own). The demo video also slows down playback of the LEDs to allow ensure that the LED can be clearly observed without worry of missing any flashes (should the video recording not have sufficient fps). On the breadboard, the top button will transmit the Standby code, then (right to left), a volume up and volume down feature. The Serial monitor displayed in the video outputs the order of buttons pressed to confirm which function has been requested.

## Approximate Costs:
* ~ $0.83 per PCB Unit
* $5 per IC controller Unit
* $0.20 per IR Transmitter Unit (IR "LED")
* ~ $1.00 per unit plastic housing
* ~ $0.31 per switch (Including power, volume+/-, numeric keypad, ~$4.03 per unit)
* Approximate Total: $11-12 per remote control unit

## IR Protocol
This code relies on the RC-5 Protocol in order to optimize for compatibility. The utilized RC library abides by this convention as described in the reference below. A readily available command table dictates what data to output through the IR LED in order to execute a given instruction. This could theoretically be applied to a number of devices, not only TVs.

Reference: [RC-5 Protocol Review](https://www.sbprojects.net/knowledge/ir/rc5.php)

## Power Management
* 9V powered unit (batteries provided by user)
* Interrupt driven signal from switches
* Assuming approximately 5mA power draw (to power IC, negligible power draw from switches, power IR transmitter for minimal amounts of time)
* Approximate run time ~ 20 days (w/ constant use)
* Approximate run time (sleep mode) ~ 66 years

Some precautions must be taken with the programming of the device to effectively coordinate the sleep mode of the device and lower it to a short clock cycle w/ low input voltage (Arduino can be adjusted to operate on lower input voltage)
