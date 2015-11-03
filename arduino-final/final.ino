//#include <Servo.h>
#include <LiquidCrystal.h>
#include "pitches.h"

#define LCD_LIGHT_PIN A4 
#define LCD_LIGHT_ON_TIME 60000

#define trigPin 13
#define echoPin 12

//Servo myservo;
//int pos = 0;
int photoPin = A0;
int buzzerPin = 4;
int ledPin = 2;


LiquidCrystal lcd(8, 9, 5, 6, 7, 3);

unsigned int currentLcdLightOnTime = 0;
// For calculating the lcd light on time.
unsigned long lcdLightOn_StartMillis;
 
boolean isLcdLightOn;

int melody[] = {
  NOTE_C4, NOTE_CS8, NOTE_G3, NOTE_F7, NOTE_G3, NOTE_F7, NOTE_DS6, NOTE_B6,NOTE_C4, NOTE_CS8,NOTE_C4, NOTE_CS8
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 4, 2, 8, 2, 32, 16, 4, 16, 2, 16,2
};


void setup() {
  
 // myservo.attach(2);
 Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(photoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);


  pinMode(LCD_LIGHT_PIN, OUTPUT);
  // Set the lcd display backlight anode pin to low - lcd light off.
  digitalWrite(LCD_LIGHT_PIN, LOW);
  isLcdLightOn = false;

 

}

 /*  for(pos = 0; pos<180; pos+=1)
  {
    myservo.write(pos);
    //delay(15);
  }
  for(pos = 180; pos>=1; pos-=1)
  {
    myservo.write(pos);
    //delay(10);
  }
  */
  /*#include <Servo.h>
 
Servo myservo;  // สร้านออปเจ็กชื่อ myservo จากคลาส Servo เพื่อควบคุม servo
 
int potpin = 0;    // ขาอะนาล็อกใช้ต่อกับตัวต้านทานปรับค่าได้
int val;               // ใช้เก็บค่าที่อ่านได้จากตัวต้านทานปรับค่าได้
 
void setup()
{
  myservo.attach(9);  // บอกว่าจะต่อ servo ที่ขา 9
}
 
void loop()
{
  val = analogRead(potpin);             // อ่านค่าอะนาล็อกจากตัวต้านทานปรับค่าได้
  val = map(val, 0, 1023, 0, 179);     // แปลงช่วง 0-1023 ที่อ่านได้ ให้อยู่ในช่วง 0-179
  myservo.write(val);                       // ส่งค่าไปควบคุม servo เป็นมุมที่ต้องการในช่วง 0-179 องศา
  delay(15);                                   // หน่วงเวลาให้ servo ได้ทำงาน
}

*/
 
void loop() {
  
  
                   

//distence sensor & lcd screen  
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

 
  if (distance < 15) {  // This is where the LED On/Off happens\
      lcd.begin(16, 2);
      lcd.setCursor(0, 0); // First row.
      lcd.print("Do NOT open the");
      lcd.setCursor(3, 1); // Second row.
      lcd.print("box, GO AWAY ");
      lcd.display();
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = true;
    digitalWrite(LCD_LIGHT_PIN, HIGH);

  }
  else{
      lcd.begin(16, 2);
      lcd.setCursor(0, 0); // First row.
      lcd.print("Come to the box");
      lcd.setCursor(3, 1); // Second row.
      lcd.print("Come on!");
      lcd.display();
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = false;
    digitalWrite(LCD_LIGHT_PIN, HIGH);
  }
  if (distance >= 200 || distance <= 0){
    //Serial.println("Out of range");
  }
  else {
    //Serial.print(distance);
    //Serial.println(" cm");
  }
  delay(500);
  


//photoresisror & buzzer
int photoVal = analogRead(photoPin);
//Serial.println(photoVal);
 if(photoVal>350){

      lcd.begin(16, 2);
      lcd.setCursor(0, 0); // First row.
      lcd.print("You Bad!! Do NOT");
      lcd.setCursor(0, 1); // Second row.
      lcd.print("taking the ring!");
      lcd.display();
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = false;
    digitalWrite(LCD_LIGHT_PIN, HIGH);
    digitalWrite(2,HIGH);
    for (int thisNote = 0; thisNote < 11; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(4, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 2.00;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(4);
    
   }
 }else{
  noTone(4);
  digitalWrite(2,LOW);
  
 
 }
}








