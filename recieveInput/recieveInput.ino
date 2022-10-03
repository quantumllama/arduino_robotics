// DualMAX14870MotorShield - Version: Latest 
#include <DualMAX14870MotorShield.h>
// Serial comms lib
#include <Wire.h>

#define LED_PIN 13

DualMAX14870MotorShield motors;
int motorSpeed = 200;

boolean firstTime = true;
int dir = 0;
int lastDir = 0;

void setup()
{
  // Setup serial comms
  Serial.begin(9600); // Baud must be the same on both arduinos

  // Setup motor drivers
  motors.enableDrivers();
  // Uncomment to flip motor directions
  // motors.flipM1(true);
  // motors.flipM2(true);
}


void loop()
{
  while(Serial.available() > 0)
  {
    if(firstTime)
    {
      lastDir = Serial.parseInt();
      firstTime = false;
      if(lastDir >= 0 && lastDir <= 4)
        setDirection(lastDir);
      else
        setDirection(0); 
    }
    
    //Serial.println("firstTime complete");
    
    dir = Serial.parseInt();
    if(dir != lastDir)
    {
      lastDir = dir;
      resetMotors(lastDir);
    }
  }
}


void setDirection(int recieved)
{
  if(recieved == 1)
  {
    // Robot forward
    motors.setM1Speed(motorSpeed);
    motors.setM2Speed(motorSpeed);
  }
  else if(recieved == 2)
  {
    // Robot backward
    motors.setM1Speed(-motorSpeed);
    motors.setM2Speed(-motorSpeed);
  }
  else if(recieved == 3)
  {
    // Robot turn left
    motors.setM1Speed(-motorSpeed);
    motors.setM2Speed(motorSpeed);
  }
  else if(recieved == 4)
  {
    // Robot turn right
    motors.setM1Speed(motorSpeed);
    motors.setM2Speed(-motorSpeed);
  }
  else
  {
    // Robot stationary
    motors.setSpeeds(0, 0);
  }
  
  stopIfFault();
}


void resetMotors(int recieved)
{
  motors.disableDrivers();

  delay(100);
  if(dir >= 0 && dir <= 4)
    setDirection(recieved);
  else
    setDirection(recieved);
  
  motors.enableDrivers();
}
 

// Check if there is a motor fault, hang forever if true
void stopIfFault()
{
  if(motors.getFault())
  {
    motors.disableDrivers();
    
    while(1)
    {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  }
}
