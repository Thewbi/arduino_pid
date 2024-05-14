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

// write a value between 0-255 to set the work duty.
// Assumption: input voltage is 12V DC
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