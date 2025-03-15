#include <Stepper.h>
#include <AccelStepper.h>


// Set all pin outputs
const int xStep       = 2;
const int xDir        = 3;

int customDelayMapped = 450;
AccelStepper stepperX(1, 2, 3); // (Type of driver: with 2 pins, STEP, DIR)


void setup() {

  Serial.begin(9600); 
  
  // Set all pins for motor outputs
  pinMode(xStep,  OUTPUT);
  pinMode(xDir,   OUTPUT);

  // calibrate motors to (0,0,0)
  // calibrate(xDir,xStep,xSwitchPin);
  // stepperX.setMaxSpeed(1000);  // Set constant speed
  // stepperX.setAcceleration(300);

  // Serial.println("Moving to 50...");
  // stepperX.moveTo(50);
  // while (stepperX.distanceToGo() != 0) {
  //   Serial.println("hellow");
  //     stepperX.runSpeedToPosition();  // Moves at constant speed, no acceleration
  // }

  // delay(100); // Small pause

  // Serial.println("Moving to -50...");
  // stepperX.moveTo(-50);
  // while (stepperX.distanceToGo() != 0) {
  //     stepperX.runSpeedToPosition();
  // }

  // Serial.println("Move complete!");
  calibrate(xDir,xStep)

}


void loop()
{
  // Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  // digitalWrite(xStep, HIGH);
  // delayMicroseconds(customDelayMapped);
  // digitalWrite(xStep, LOW);
  // delayMicroseconds(customDelayMapped);
  // stepper1.setSpeed(500);
  // stepper1.runSpeed();


    // stepperX.run();         // Non-blocking movement

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
