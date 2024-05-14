/*
 * Current Sensing with Arduino Motor Shield
 * 
 * Written by Ahmad Shamshiri for Robojax.com on Aug 31, 2018 at 17:40 in Ajax, Ontario, Canada
 * Watch video instruction for this code: https://youtu.be/-uQKBDTWHPM
 * This code needs watching introduction to Arduino Motor Shield
 * which you can watch it here:https://youtu.be/kIgbjyqNrV8
 
     This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
const int MotorPinA = 12; 
const int MotorSpeedPinA = 3;
const int MotorBrakePinA = 9;
const int currentSenseA = A0;


const int MotorPinB = 13;
const int MotorSpeedPinB = 11;
const int MotorBrakePinB = 8;
const int currentSenseB = A1;

const int CW  = HIGH;// variable for clockwise rotation
const int CCW = LOW;// variable for counterclockwise rotation

const int showComments = 1;// show comments in serial monitor
const double currentFactor = 2/3.3;// 3.3V per 2A which is 0.909

void setup() {
  // motor A pin assignment
  pinMode(MotorPinA, OUTPUT);// define motor pin as output
  pinMode(MotorSpeedPinA, OUTPUT);//define motor speed control pin
  pinMode(MotorBrakePinA, OUTPUT);// define motor brake pin

  // motor B pin assignment
  pinMode(MotorPinB, OUTPUT);
  pinMode(MotorSpeedPinB, OUTPUT);
  pinMode(MotorBrakePinB, OUTPUT); 


  Serial.begin(9600);//  seial monitor initialized 

  brake('B', 0); // release brake

}

double filter[20];

void loop() {
  
  

  moveMotor('A', CW, 255);// start motor B in CW direction with 255 PWM value
  //Serial.print("Current at 255:");

  int readA = analogRead(currentSenseA);
  Serial.print("readA:");
  Serial.print(readA);
  Serial.print(",");

  double currentVA = (float) map(readA, 0, 1024, 0, 5000) / 1000.0f;
  double currentA = currentVA*currentFactor;// get channel A current from voltage and current factor (from data sheet)


  int readB = analogRead(currentSenseB);
  Serial.print("readB:");
  Serial.print(readB);
  Serial.print(",");

  double currentVB = (float) map(readB, 0, 1024, 0, 5000) / 1000.0f;
  double currentB = currentVB*currentFactor;// get channel B current from voltage and current factor (from data sheet)


  double current_filtered = 0;
  for (int i = 0; i < 20; i++) {
    filter[i] = filter[i+1];
    current_filtered += filter[i];
  }
  filter[19] = currentA;
  current_filtered += currentA;
  current_filtered /= 20.0f;
  
    
  if(currentA > 1.25)
  {
    brake('A', 1);// apply brake
    brake('A', 0);// release brake
    // change the rotation direction to CCW
    moveMotor('A', CCW, 255);
  }
  Serial.print("currentA:");
  Serial.println(current_filtered);// print the current
  delay(20);


}// loop end



/*
 * 
 * Written by Ahmad Shamshiri August 29 2018 at 20:59 in Ajax, Ontario, Canada 
 * moveMotor controls the motor
  @param motor is char A or B refering to motor A or B.
  @param dir is motor direction, CW or CCW
  @speed is PWM value between 0 to 255

  Example 1: to start moving motor A in CW direction with 135 PWM value
  moveMotor('A', CW, 135);

  Example 2: to start moving motor B in CCW direction with 200 PWM value
  moveMotor('B', CCW, 200);  
 */

void moveMotor(char motor, int dir, int speed)
{
  int motorPin;
  int motorSpeedPin;
  
  if(motor =='A')
  {
    motorPin      = MotorPinA;
    motorSpeedPin = MotorSpeedPinA;  
  }else{
    motorPin      = MotorPinB;
    motorSpeedPin = MotorSpeedPinB;     
  }
   digitalWrite(motorPin, dir);// set direction for motor
   analogWrite(motorSpeedPin, speed);// set speed of motor   
}//moveMotor end

/*
 * brake, stops the motor, or releases the brake
 * @param motor is character A or B
 * @param brk if  1 brake, if 0, release brake
 * example of usage:
 * brake('A', 1);// applies brake to motor A
 * brake('A', 0);// releases brake from motor A
 */
void brake(char motor, int brk)
{
  if(motor =='A')
  {
    digitalWrite(MotorBrakePinA, brk);// brake
    delay(1000);
  }else{
    digitalWrite(MotorBrakePinB, brk);// brake
    delay(1000);
   
  }
}