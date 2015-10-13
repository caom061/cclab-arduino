int eyeledPin = 13;
int noseledPin = 12;
int mouseledPin = 8;
int button1Pin = 2;
int button2Pin = 4;
int button3Pin = 7;


int button1State = 0; 
int button2State = 0;
int button3State = 0;  

void setup() {
pinMode(eyeledPin, OUTPUT);
pinMode(noseledPin, OUTPUT);
pinMode(mouseledPin, OUTPUT);
pinMode(button1Pin, INPUT);
pinMode(button2Pin, INPUT);
pinMode(button3Pin, INPUT);

}

void loop() {
button1State = digitalRead(button1Pin);
button2State = digitalRead(button2Pin);
button3State = digitalRead(button3Pin);

if (button1State == HIGH){
  digitalWrite(eyeledPin, HIGH);
  delay(500);
  digitalWrite(eyeledPin, LOW);
  delay(500);
  digitalWrite(eyeledPin, HIGH);
  delay(1000);
  digitalWrite(eyeledPin, LOW);
  delay(500);
  digitalWrite(eyeledPin, HIGH);
  delay(100);
  digitalWrite(eyeledPin, LOW);
  delay(1000);
  //digitalWrite(eyeledPin, HIGH);
}else {
  digitalWrite(eyeledPin, LOW);
}
  
  if (button2State == HIGH){
  digitalWrite(noseledPin, HIGH);
  delay(100);
  digitalWrite(noseledPin, LOW);
  delay(400);
  digitalWrite(noseledPin, HIGH); 
  delay(400);
  digitalWrite(noseledPin, LOW);
  delay(100);
  digitalWrite(noseledPin, HIGH);
  delay(500);
  digitalWrite(noseledPin, LOW);
  delay(400);
  digitalWrite(noseledPin, HIGH); 
  delay(100);
  digitalWrite(noseledPin, LOW);
  delay(1000);
  //digitalWrite(noseledPin, HIGH); 
  
}else{
  digitalWrite(noseledPin, LOW);
}
  

  if (button3State == HIGH){
  digitalWrite(mouseledPin, HIGH);
  delay(100);
  digitalWrite(mouseledPin, LOW);
  delay(400);
  digitalWrite(mouseledPin, HIGH); 
  delay(400);
  digitalWrite(mouseledPin, LOW);
  delay(1000);
  digitalWrite(mouseledPin, HIGH);
  delay(100);
  digitalWrite(mouseledPin, LOW);
  delay(400);
  digitalWrite(mouseledPin, HIGH); 
  delay(400);
  digitalWrite(mouseledPin, LOW);
  delay(100);
 // digitalWrite(mouseledPin, HIGH); 


}else{
  digitalWrite(mouseledPin, LOW);
}

if(button1State == HIGH && button2State == HIGH){
  digitalWrite(eyeledPin, HIGH);
  digitalWrite(noseledPin, HIGH); 
  digitalWrite(mouseledPin, HIGH);
  delay(1000);
  digitalWrite(eyeledPin, LOW);
  digitalWrite(noseledPin, LOW); 
  digitalWrite(mouseledPin, LOW);
  delay(100);
  digitalWrite(eyeledPin, HIGH);
  digitalWrite(noseledPin, HIGH); 
  digitalWrite(mouseledPin, HIGH);
  delay(100);
  digitalWrite(eyeledPin, HIGH);
  digitalWrite(noseledPin, HIGH); 
  digitalWrite(mouseledPin, HIGH);
  delay(1000);

}else{
  digitalWrite(eyeledPin, LOW);
  digitalWrite(noseledPin, LOW); 
  digitalWrite(mouseledPin, LOW);
  
  
}
}



