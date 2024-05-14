# Introduction

The purpose of this test is to get to know the encoder and it's output in isolation from all other features of a PID control system.
No PID controller is involved. After the test, it is validated that:

- the power supply works
- the motor works
- which wire on the motor is used for which purpose
- the wiring is correct
- the motor encoder works
- the arduino works
- the signals that the encoder outputs can be converted to meaningful information on the arduino.

This first test will use a DC power supply to drive the motor at constant speed based on the voltage supplied.
It will read signals from the DC motor's encoder and process the encoder signals using the Arduino.

This encoder test lays the groundwork for a closed loop system used in later steps.

## Motor and wiring

The motor used is the JGB-520.
It is a 12V DC motor that goes up to 1000 RPM according to the label on the housing.

eBay: https://www.ebay.de/itm/166471920023?mkcid=16&mkevt=1&mkrid=707-127634-2357-0&ssspo=zsyxprhrtzy&sssrc=2047675&ssuid=plgx2AkNTy-&widget_ver=artemis&media=COPY

![JGB-520](images/s-l1600.jpg)