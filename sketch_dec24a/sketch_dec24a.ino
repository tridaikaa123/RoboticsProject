#include <Servo.h>

int32_t theta1;
int32_t theta2;
int32_t theta3;

int vt1;
int vt2;
int vt3;

char dl;
String data;
String x;

int32_t theta1dat = 0;
int32_t theta2dat = 0;
int32_t theta3dat = 0;

int en=8;

const int stepPinX = 2; 
const int dirPinX = 5; 

const int stepPinY = 3;
const int dirPinY = 6;

const int stepPinZ = 4;
const int dirPinZ = 7;
/////////Test Servo//////////////
Servo myServo;
char c;
String dataIn;
int32_t deg;
int vt4;

void setup() {
  pinMode(en,OUTPUT); 
  pinMode(stepPinX,OUTPUT); 
  pinMode(dirPinX,OUTPUT);
  pinMode(stepPinY,OUTPUT); 
  pinMode(dirPinY,OUTPUT);
  pinMode(dirPinZ,OUTPUT);
  pinMode(stepPinZ,OUTPUT);
  digitalWrite(en,LOW);
  Serial.begin(9600);

  myServo.attach(11);
}

void loop() {
  myServo.write(deg);
  while(Serial.available()== 0);
  data = Serial.readString();
  dl = data.charAt(0);
  if (dl == 'a' ) {
    vt1 = data.indexOf('a');
    vt2 = data.indexOf('b');
    vt3 = data.indexOf('c');
    theta1 = data.substring(vt1+1,vt2).toInt();
    theta2 = data.substring(vt2+1,vt3).toInt();
    theta3 = data.substring(vt3+1).toInt();
    
  }
  else if( dl == 'r' )
  {
    theta1 = 0;
    theta2 = 0;
    theta3 = 0;
  }
  else if(dl == 'd')
  {
    vt4 = data.indexOf('d');
    deg = data.substring(vt4+1).toInt();
    Serial.println(deg);
  }
  myServo.write(deg);

  if(theta1 > theta1dat)
  {
    for( int x = 0 ; x < (theta1 - theta1dat)/1.8 *3.75 ; x++) 
    {
        digitalWrite(dirPinX,HIGH);
        digitalWrite(stepPinX,HIGH); 
        delayMicroseconds(3800); 
        digitalWrite(stepPinX,LOW); 
        delayMicroseconds(3800);
    }            
  }
  else {
    for( int x = 0 ; x < (theta1dat - theta1)/1.8 *3.75 ; x++) 
    {   
      digitalWrite(dirPinX,LOW);          
      digitalWrite(stepPinX,HIGH); 
      delayMicroseconds(3800);
      digitalWrite(stepPinX,LOW); 
      delayMicroseconds(3800);
      }
    }

    delay(1000);
    if(theta2 > theta2dat)
    {
      for( int y = 0 ; y < (theta2 - theta2dat)/1.8 *3 ; y++) {
        digitalWrite(dirPinY,HIGH);
        digitalWrite(stepPinY,HIGH);
        delayMicroseconds(3800); 
        digitalWrite(stepPinY,LOW);
        delayMicroseconds(3800);
      }
    }
    else
    {
      for( int y = 0 ; y < (theta2dat - theta2)/1.8 *3 ; y++) 
      {
          digitalWrite(dirPinY,LOW);
          digitalWrite(stepPinY,HIGH);
          delayMicroseconds(3800); 
          digitalWrite(stepPinY,LOW);
          delayMicroseconds(3800);
      }
    }

    delay(1000);
    if(theta3 > theta3dat) 
    {
      for( int z = 0 ; z < (theta3 - theta3dat)/1.8 *3.75 ; z++) 
      {
        digitalWrite(dirPinZ,HIGH);
        digitalWrite(stepPinZ,HIGH); 
        delayMicroseconds(2400); 
        digitalWrite(stepPinZ,LOW);
        delayMicroseconds(2400);
      }
    }
    else 
    {
      for( int z = 0 ; z < (theta3dat - theta3)/1.8 *3.75 ; z++)
        {   
          digitalWrite(dirPinZ,LOW);          
          digitalWrite(stepPinZ,HIGH); 
          delayMicroseconds(2400); 
          digitalWrite(stepPinZ,LOW); 
          delayMicroseconds(2400);
        }
    }

    theta1dat = theta1;
    theta2dat = theta2;
    theta3dat = theta3;
 }
