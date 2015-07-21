#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motorLeft = AFMS.getMotor(1);
Adafruit_DCMotor *motorRight = AFMS.getMotor(2);
int dir = 0;
int lastDir = 0;
boolean firstTime = true;

void setup() {
Serial.begin(9600);//Remember that the baud must be the same on both arduinos
AFMS.begin();
motorLeft->setSpeed(200);
motorRight->setSpeed(200);
}
void loop() {
  while(Serial.available() > 0) {
    if(firstTime){
      lastDir = Serial.parseInt();
      firstTime = false;
      if(lastDir >= 0 && lastDir <= 4)
        setDirection(lastDir);
      else
        setDirection(0); 
    }
    //Serial.println("You've reached me!");
    dir = Serial.parseInt();
    if(dir != lastDir){
      lastDir = dir;
      resetMotors(lastDir);
    }
}
}

void setDirection(int recieved){
  if(recieved == 1)
  {
    motorLeft->run(FORWARD);
    motorRight->run(FORWARD);
  }
  else if(recieved == 2)
  {
    motorLeft->run(BACKWARD);
    motorRight->run(BACKWARD);
  }
  else if(recieved == 3){
    motorLeft->run(BACKWARD);
    motorRight->run(FORWARD);
  }
  else if(recieved == 4){
    motorLeft->run(FORWARD);
    motorRight->run(BACKWARD);
  }
  else{
    motorLeft->run(RELEASE);
    motorRight->run(RELEASE);
  } 
}
 void resetMotors(int recieved){
    motorLeft->run(RELEASE);
    motorRight->run(RELEASE);
    delay(100);
    if(dir >= 0 && dir <= 4)
      setDirection(recieved);
    else
      setDirection(recieved); 
 }
