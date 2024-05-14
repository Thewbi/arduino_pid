# Introduction

https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/

To excert finer control over a motor, a motor driver such as the L298P on the arduino motor shield rev3 can be used.

The L298P contains a motor bridge which allows a microcontroller to electronically define which fraction of the input voltage is 
fed into the DC motor and in which polarity the voltage is applied.

Speed and direction of rotation can be controlled from within an arduino sketch.

The Arduino motor shield also has a current sensing function which allows us to build a closed loop taking current as target value
or limit a motor circuit based on current.

This example does not make use of the motor encoder. It is purely controlling the voltage supplied to the motor using an arduino sketch.

After the test, it is validated that:

- the motor shield works
- the motor shield has proper connection to the arduino
- the PWM signal is a value between 0 and 255 which can be used to limit the voltage provided by the external power supply based on a value set in a arduino sketch
- the motor works
- the morot is able to function using a voltage controlled via PWM


## Cuttin Vin Connect on the Arduino Motor Shield rev3

On the bottom of the board, there is a bridge between two solder pads called "Vin Connect".
If this bridge is connected (which it initially is in the boards factory condition) then the voltage
supplied to the motor shield is also transmitted into the arduino.

The arduino is permanently damaged when it sees more than 9V.

I the case of the JGB-520 motor used in this example this becomes a problem since the JGB-520 needs 0 to 12V in order
to operate. 12V damages the arduino. Therefore, the solder bridge is cut using a scalpel or a box cutter. Alternatively
the solder bridge may be removed using a soldering iron. In any case, to make sure that the connection between the external
powersource and the arduino is severed, use a measurring device in continuite mode and check for a lack of continuity.

## What is PWM

PWM stands for pulse width modulation. The width of a pulse can be controlled.

For DC motors, the motor's velocity is directly correlated to the input voltage and the direction to the polarity of that voltage.

In motor control for DC motors, the problem to solve is how to supply varying voltage levels to the motor in order to control it's velocity 
(= the speed at which it turns the shaft).

One way would be to have a variable resistor (similar to a potentiometer) which is able to drop voltage given an input voltage so that only
a fraction of the input voltage makes it to the motor.

Another idea is to not drop any voltage from the input voltage but to just completely disconnect the input voltage from the motor for 
certain fractions of time. If the input voltage is 12V and we only connect the motor 50% of the time over very short timeslices, the motor
sees an effective voltage of 6V.

This is exactly the idea of PWM. PWM is rapidly connecting and disconnecting the voltage line. From within the source code, the programmer
defines the ratio between on and off periods in the range from 0% to 100%. In the arduino sketch 0% correlates to a PWM value of 0 and 
100% to a value of 255.

PWM for the voltage is feature of the arduino motor shield rev3. For port A, pin 3 is used for PWM. For port B pin 11 is used.

## Wiring

Put the motor shield on top of the arduino. You can test the motor shield connectivity by pressing the reset button
on the motor shield and watching what the arduino does. The arduino has to reset when you push the reset button on the 
motor shield.

Connect the motor's power cables to the channel A of the motor shield (polarity does not matter). Use the RED wire and the WHITE wire of the JGB-520 motor.
Now run your external power supply at the upper voltage constantly. The arduino rev 4 shield takes care of alternating the voltage using PWM.
Meaning, in the case of the JGB-520 motor which operates between 0V and 12V, set the external powersupply to 12V constantly and feed this
voltag into the motor shield. The output port A of the motor shield will output a voltage to the motor that ranges between 0V and 12V based on
the PWM signal set via the sketch running on the arduino. The PWM signal ranges from 0 to 255. 0 means 0V and 255 means max input voltage (12V in this example)

## Code

The code is taken from here: https://docs.arduino.cc/tutorials/motor-shield-rev3/msr3-controlling-dc-motor/

It is slightly modifed

```
// uncomment if using channel A, and remove below definitions
int directionPin = 12;
int pwmPin = 3;
int brakePin = 9;

// uncomment if using channel B, and remove above definitions
//int directionPin = 13;
//int pwmPin = 11;
//int brakePin = 8;

// boolean to switch direction
bool directionState;

//write a value between 0-255 to set the work duty.
//int pwm = 50; // +- 2.4V
//int pwm = 80; // +- 3.8V
int pwm = 255; // +- 11.5V

void setup() {

  // define pin directions
  pinMode(directionPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(brakePin, OUTPUT);

}

void loop() {

  //
  // direction
  //

  // change direction every loop()
  directionState = !directionState;
  if (directionState == false) {

    // write a low state to the direction pin (13)
    digitalWrite(directionPin, LOW);

  } else {

    // write a high state to the direction pin (13)
    digitalWrite(directionPin, HIGH);
  }

  //
  // drive the motor
  //

  // release breaks
  digitalWrite(brakePin, LOW);

  // set work duty for the motor
  analogWrite(pwmPin, pwm);

  delay(2000);

  //
  // stop the motor
  //

  // activate breaks
  digitalWrite(brakePin, HIGH);

  // set work duty for the motor to 0 (off)
  analogWrite(pwmPin, 0);

  delay(2000);
  
}
```