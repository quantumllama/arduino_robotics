void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0/1023.0);
  
  //print out the value you read:
  //Serial.println(voltage);
  //Serial.println("input one");
  //Serial.println(voltage2);
  //Serial.println("input two");
  //delay(1000);
  
  //convert input into sendable output
  float inputX = voltage - 2.5;
  float inputY = voltage2 - 2.5;

  //deadzone
  if(inputX > -.25 && inputX < .25){
    inputX = 0;
  }
  if(inputY > -.25 && inputY < .25){
    inputY = 0;
  }
  //Serial.println(inputX);
  //Serial.println(inputY);
  delay(10);
   //choose direction, 1 North, 2 South, 3 East, 4 West
  if(inputX == 0 && inputY == 0){
    Serial.println("0");
  }
  else if(abs(inputX) > abs(inputY)){
    if(inputX > 0){
      Serial.println("1");
    }
    else {
      Serial.println("2");
    }
  }
  else if(abs(inputY) > abs(inputX))
  {
    if(inputY > 0){
      Serial.println("3");
    }
    else {
      Serial.println("4");
    }
  }
  else if(inputX == inputY && inputX != 0)
  {
    if(inputX > 0){
      Serial.println(1);
    }
    else {
      Serial.println(3);
    }
  }
  delay(100);
}



