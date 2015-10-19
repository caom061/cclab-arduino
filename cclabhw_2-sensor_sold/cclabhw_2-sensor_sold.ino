#include <LiquidCrystal.h>

//#define BUTTON_PIN A5
//#define BUTTON2_PIN A3
#define LCD_LIGHT_PIN A4 
#define LCD_LIGHT_ON_TIME 60000

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

LiquidCrystal lcd(8, 9, 5, 6, 7, 3);

unsigned int currentLcdLightOnTime = 0;
// For calculating the lcd light on time.
unsigned long lcdLightOn_StartMillis;
 
boolean isLcdLightOn;


void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  lcd.begin(16, 2);
  lcd.setCursor(0, 0); // First row.
  lcd.print("Do NOT NOT NOT");
  lcd.setCursor(3, 1); // Second row.
  lcd.print("open the box! ");
  lcd.display();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

//  pinMode(BUTTON_PIN, INPUT);
  // Set the lcd display backlight anode pin as an output.
 // pinMode(BUTTON2_PIN, INPUT);
  pinMode(LCD_LIGHT_PIN, OUTPUT);
  // Set the lcd display backlight anode pin to low - lcd light off.
  digitalWrite(LCD_LIGHT_PIN, LOW);
  isLcdLightOn = false;


  
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

 
  if (distance < 15) {  // This is where the LED On/Off happens
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = true;
    digitalWrite(LCD_LIGHT_PIN, HIGH);
  }
  else{
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = false;
    digitalWrite(LCD_LIGHT_PIN, LOW);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}








