#include <Servo.h>
Servo myservo;
int pos = 0;
int sensorPin = A5;

void setup() {
  
  myservo.attach(2);
  Serial.begin(9600);
  
}

void loop() {
  
  
  for(pos = 0; pos<180; pos+=1)
  {
    myservo.write(pos);
    delay(10);
  }
  for(pos = 180; pos>=1; pos-=1)
  {
    myservo.write(pos);
    delay(10);
  }
  int sensor = analogRead(sensorPin);
  int output = map(sensor, 730, 900, 0, 255);
    //Serial.print("analog input: ");
    //Serial.print(sensor,DEC);
    //Serial.print(" output: ");
   // Serial.println(output);
    Serial.print(output);
    Serial.print(':');
    
  
  
}
