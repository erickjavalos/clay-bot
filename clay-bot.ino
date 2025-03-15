#include <Stepper.h>
#include <AccelStepper.h>

// corespond to LOW and HIGH
#define POS 0
#define NEG 1

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

int timeStep = 1200;

float xDist_mm = 0.0;
float yDist_mm = 0.0;
float zDist_mm = 0.0;

float stepDistance = 0.2; // linear distance calculated with 20 teeth, 2mm distance between teeth, and takes 200 steps per cycle

bool squareDrawn = 0;

float xCenter = 140.0;
float yCenter = 70.0;


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


  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  // calibrate motors to (0,0,0)
  calibrate(xDir,xStep,xSwitchPin);
  calibrate(yDir,yStep,ySwitchPin);
  calibrateZ(zDir,zStep,zSwitchPin);

  // circle();
  xDist_mm = 0.0;
  yDist_mm = 0.0;
  zDist_mm = 0.0;
  
}


void loop()
{
  if (!squareDrawn){
    drawSquare();
    printHello();

    squareDrawn = 1;
  }

  



}

void drawSquare(){
  // 1. move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  // move to top left corner (-x,+y)
  int xDesired = 20.0;
  int yDesired = 180.0;

  // move to top x left
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  // move to top y left
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

  // start marking! 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  delay(500);

  // move to right
  xDesired += 260.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  delay(100);
  // move down
  yDesired -= 160.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }

  delay(100);
  // move left
  xDesired -= 260.0;
  while (xDist_mm > xDesired){
    move(xDir,xStep,NEG);
    xDist_mm -= stepDistance;
  }
  delay(100);
  // move up
  yDesired += 160.0;
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }
  delay(100);



  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 




  squareDrawn = 1;

}

void printHello(){
  
  drawH();
  drawE();
  drawL();
  drawL();
  drawO();
  printEx();

  Serial.println(xDist_mm);
  Serial.println(yDist_mm);


}

void drawH(){
  // 1. move up so marker doesnt hit
  // while (zDist_mm < 20.0){
  //   move(zDir,zStep,POS);
  //   zDist_mm += stepDistance;
  // } 

  // 2. go to start of H. 
  // move to top left corner (-x,+y)

  int xDesired = 70.0;
  int yDesired = 140.0;

  // move to top x left
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  // move to top y left
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }

  delay(500);

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  delay(100);
  // move down
  yDesired -= 80.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }

  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  yDesired += 40.0;
  // move to top y left
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

  delay(100);

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  // move to right
  xDesired += 20.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  delay(100);
  // move down
  yDesired -= 40.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }

  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  yDesired += 40.0;
  // move to top y left
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  yDesired += 40.0;
  // move to top y left
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 


}

void drawE(){
  // move to right
  float xDesired = xDist_mm + 10.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  delay(100);
  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 
  delay(100);

  // move down
  int yDesired = yDist_mm - 80.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }

  delay(100);
  // move to right
  xDesired += 20.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  delay(100);

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 
  delay(100);
  yDesired += 40.0;
  // move to top left
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 


  delay(100);
  xDesired -= 20;
  while (xDist_mm > xDesired){
    move(xDir,xStep,NEG);
    xDist_mm -= stepDistance;
  }

   // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 
  yDesired += 40;
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 
  
  xDesired += 20.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 
  

}

void drawL(){

  float xDesired = xDist_mm + 10.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  // move down
  int yDesired = yDist_mm - 80.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }

  delay(100);

  // move to right
  xDesired += 20.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  delay(100);

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  yDesired += 80;
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }


}

void drawO(){

  float xDesired = xDist_mm + 10.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  // move to right
  xDesired += 20.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  delay(100);

  // move down
  int yDesired = yDist_mm - 80.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }
  delay(100);

  xDesired -= 20.0;
  while (xDist_mm > xDesired){
    move(xDir,xStep,NEG);
    xDist_mm -= stepDistance;
  }
  delay(100);

  yDesired += 80.0;
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }
  
  delay(100);

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  xDesired += 20.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }
  

}

void printEx(){
  float xDesired = xDist_mm + 10.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }

  // mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  // move down
  float yDesired = yDist_mm - 70.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }
  delay(100);

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  // move down
  yDesired = yDist_mm - 10.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }
  delay(100);

  // mark the floor
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

  // move up so marker doesnt hit
  while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

  yDesired += 80.0;
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }
  

}

void goCenter(){

  // go to desired x,y location!
  while (xDist_mm < xCenter){
    // perform one step
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }

  while (yDist_mm < yCenter){
    // perform one step
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }

}
// increases the position
void move(int dir, int step, int dirState){

  digitalWrite(dir,dirState);
  // perform step input
  digitalWrite(step,HIGH);
  delayMicroseconds(timeStep);
  digitalWrite(step,LOW);
  delayMicroseconds(timeStep);
}

// increases the position
void moveZPositive(int dir, int step){

  digitalWrite(dir,LOW);
  // perform step input
  digitalWrite(step,HIGH);
  delayMicroseconds(timeStep);
  digitalWrite(step,LOW);
  delayMicroseconds(timeStep);
}

void calibrate(int dir, int step, int switchPin)
{
  // stepperX.moveTo(-5000);
  int switchState = digitalRead(switchPin);  // Read the state of the switch
  
  // set direction of motor to spin to
  digitalWrite(dir,HIGH);
  while (!switchState) {

    digitalWrite(step,HIGH);
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);

    // stepperX.run(); 

    // delay(1);
    // recieve update to sensor 
    switchState = digitalRead(switchPin);
  }

  Serial.println("Switch engaged found initial");
  delay(1000);

  // // switch directions, go back to 0...

  digitalWrite(dir,LOW);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);
  }

  delayMicroseconds(500);
  // switch directions, go back to 0...

  digitalWrite(dir,HIGH);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);
  }



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
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);

    // recieve update to sensor 
    switchState = digitalRead(switchPin);
  }

  Serial.println("Switch engaged found initial");
  delay(500);

  // switch directions, go forward...

  digitalWrite(dir,LOW);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);
  }

  delayMicroseconds(500);
  // switch directions, go back to 0...

  digitalWrite(dir,HIGH);
  for (int x = 0; x < 100; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);
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

void moveZUp(int dir, int step, int switchPin){
  digitalWrite(dir,LOW);
  for (int x = 0; x < 500; x++){
    digitalWrite(step,HIGH);
    delayMicroseconds(timeStep);
    digitalWrite(step,LOW);
    delayMicroseconds(timeStep);
  }

}

void circle(){
  digitalWrite(xDir,HIGH);
  // digitalWrite(xStep,HIGH);
  for (int x = 0; x < 200; x++){
    digitalWrite(xStep,HIGH);
    delayMicroseconds(500);
    digitalWrite(xStep,LOW);
    delayMicroseconds(500);
  }

}
