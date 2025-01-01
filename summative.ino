/* Line Following Test - Written by Victor Yu
Created: 2024-01-10
Modified: 2024-01-10
Purpose: To create the fastest line following robot
*/

// declare constants for motor pins and QTI sensor pins
const int Rightsensor = 2, Leftsensor = 3;
const int LMotor_pin1 = 5, LMotor_pin2 = 6;
const int RMotor_pin1 = 9, RMotor_pin2 = 10;
const int LED_Left = 7, LED_Right = 8;

void setup(){
  // set motor pins as OUTPUTS
  pinMode(LMotor_pin1, OUTPUT);
  pinMode(LMotor_pin2, OUTPUT);
  pinMode(RMotor_pin1, OUTPUT);
  pinMode(RMotor_pin2, OUTPUT);
  pinMode(LED_Left, OUTPUT);
  pinMode(LED_Right, OUTPUT);
  
  // set the QTI sensor pins as INPUTS:
  pinMode(Leftsensor, INPUT);
  pinMode(Rightsensor, INPUT);
}

void loop(){
  // read sensor values
  bool Left_sensorValue = digitalRead(Leftsensor);
  bool Right_sensorValue = digitalRead(Rightsensor);

  // if Left sensor is black and right is white
  if ((Left_sensorValue == 1) && (Right_sensorValue == 0)){
    TURN(0);
  }
  else if ((Left_sensorValue == 0) && (Right_sensorValue == 0)){
    FORWARD(1);
  }
  // if Left sensor is white and right is black
  else if ((Left_sensorValue == 0) && (Right_sensorValue == 1)){
    TURN(1);
  }
  // if both sensors are white or black
  else{
   FORWARD(0);
  }
  delay(10);
}

void FORWARD(int boolean) {
  //Left motor stop
    analogWrite(LMotor_pin1, boolean*220);  
    analogWrite(LMotor_pin2, 0); 
    //Right motor forward
    analogWrite(RMotor_pin1, boolean*220);  
    analogWrite(RMotor_pin2, 0);
}

void TURN(int dir) {
  //Left motor stop
    if (dir == 1) {
      analogWrite(LMotor_pin1, 0);  
      analogWrite(LMotor_pin2, 150); 
      //Right motor forward
      analogWrite(RMotor_pin1, 255);
      analogWrite(RMotor_pin2, 0);
      //LED turn signal
      digitalWrite(LED_Right, HIGH);
    } else {
      analogWrite(LMotor_pin1, 255);  
      analogWrite(LMotor_pin2, 0);  
      //Right motor stop
      analogWrite(RMotor_pin1, 0);
      analogWrite(RMotor_pin2, 150);
      //LED turn signal
      digitalWrite(LED_Left, HIGH);
    }
    
}