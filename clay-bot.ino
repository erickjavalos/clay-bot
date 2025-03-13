#include <Stepper.h>

// Set all pin outputs
const int xStep       = 2;
const int xDir        = 3;
const int yStep       = 4;
const int yDir        = 5;
const int zStep      = 6;
const int zDir       = 7;

const int xSwitchPin = 10;  // Change this to your actual pin number
const int ySwitchPin = 11;  // Change this to your actual pin number
const int zSwitchPin = 12;  // Change this to your actual pin number

void setup() {

  pinMode(xSwitchPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  pinMode(ySwitchPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  pinMode(zSwitchPin, INPUT_PULLUP);  // Enable internal pull-up resistor

  Serial.begin(9600); 
  
  // Set all pins for motor outputs
  pinMode(xStep,  OUTPUT);
  pinMode(xDir,   OUTPUT);
  pinMode(yStep,  OUTPUT);
  pinMode(yDir,   OUTPUT);
  pinMode(zStep, OUTPUT);
  pinMode(zDir,  OUTPUT);

  // calibrate motors to (0,0,0)
  calibrate(xDir,xStep,xSwitchPin);
  calibrate(yDir,yStep,ySwitchPin);
  calibrateZ(zDir,zStep,zSwitchPin);
}


void loop()
{
  // calibrate the motors
  // calibrate()
  // quarterTurns(xStep,xDir);
  // quarterTurns(yStep,yDir);
  // quarterTurns(zStep,zDir);

}
// void loop() {
//   int switchState = digitalRead(switchPin);  // Read the state of the switch

//   if (switchState == HIGH) {
//     // Switch is engaged
//     Serial.println("Switch engaged");
//   } else {
//     // Switch is not engaged
//     Serial.println("Switch not engaged");
//   }

//   delay(100);  // Add a small delay for stability

// }

void calibrate(int dir, int step, int switchPin)
{
  int switchState = digitalRead(switchPin);  // Read the state of the switch
  
  // set direction of motor to spin to
  digitalWrite(dir,LOW);
  while (!switchState) {
    // Serial.println("Switch not engaged");

    // drive motor a step
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);

    // recieve update to sensor 
    switchState = digitalRead(switchPin);
  }

  Serial.println("Switch engaged found initial");
  delay(500);

  // switch directions, go forward...

  digitalWrite(dir,HIGH);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);
  }

  delayMicroseconds(500);
  // switch directions, go back to 0...

  digitalWrite(dir,LOW);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);
  }


  // if (switchState == HIGH) {
  //   // Switch is engaged
  //   Serial.println("Switch engaged");
  // } else {
  //   // Switch is not engaged
  //   Serial.println("Switch not engaged");
  // }

  delay(100);  // Add a small delay for stability

}

void calibrateZ(int dir, int step, int switchPin)
{
  int switchState = digitalRead(switchPin);  // Read the state of the switch
  
  // set direction of motor to spin to
  digitalWrite(dir,HIGH);
  while (!switchState) {
    // Serial.println("Switch not engaged");

    // drive motor a step
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);

    // recieve update to sensor 
    switchState = digitalRead(switchPin);
  }

  Serial.println("Switch engaged found initial");
  delay(500);

  // switch directions, go forward...

  digitalWrite(dir,LOW);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);
  }

  delayMicroseconds(500);
  // switch directions, go back to 0...

  digitalWrite(dir,HIGH);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);
  }


  // if (switchState == HIGH) {
  //   // Switch is engaged
  //   Serial.println("Switch engaged");
  // } else {
  //   // Switch is not engaged
  //   Serial.println("Switch not engaged");
  // }

  delay(100);  // Add a small delay for stability

}
// void loop() {
//   // put your main code here, to run repeatedly:
//   // circle();
//   quarterTurns(xStep,xDir);
//   quarterTurns(yStep,yDir);
//   quarterTurns(z1Step,z1Dir);
//   quarterTurns(z2Step,z2Dir);
// }

void quarterTurns(int step,int dir){
  // 90 degrees clockwise
  digitalWrite(dir,HIGH);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);
  }
  
  delay(200);
  // 90 degrees counter clockwise
  digitalWrite(dir,LOW);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW);
    delayMicroseconds(500);
  }  
  delay(200);

}

void circle(){
  digitalWrite(xDir,HIGH);
  // digitalWrite(xStep,HIGH);
  for (int x = 0; x < 50; x++){
    digitalWrite(xStep,HIGH);
    delayMicroseconds(500);
    digitalWrite(xStep,LOW);
    delayMicroseconds(500);
  }

}
