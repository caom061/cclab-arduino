import processing.serial.*;

Serial myport;

String portValue;
int useless;
int speedness;

PFont getwhat;


void setup(){
  size(800,600); 
  
  
  getwhat = loadFont("Kefa-Bold-30.vlw");
  
  String arduinoport = Serial.list()[3];
  myport = new Serial(this, arduinoport, 9600);
  
  
}

void draw(){
  

  
  if (myport.available() > 0) {
  portValue = myport.readStringUntil(':');
  myport.clear();
  
  
  int[]list = int(split(portValue,':'));
  
  if(list.length > 1){
    
  speedness = list[0];
  useless = list[1];
  
  println(speedness);
  
  }
  
  if (speedness < 200){
    background(0);
  }else{
    
    background(255, 0, 0, 255);
    textFont(getwhat, 26);
    text("Now you have to marry me !! lol", 200, 300);
    

  }
  }
}

