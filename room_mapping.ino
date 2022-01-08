int pingTravelTime;
float velocity=0.016667;
float distance;
int i;
int Time;
// motor board ///////////////////////////////////////////////////////////////////////////
int ENA=5;
int ENB=6;
int IN1=7;
int IN2=8;
int IN3=9;
int IN4=11;
// values from 180 degrees //////////////////////////////////////////////////////////////
float d0;
float d30;
float d60;
float d90;
float d120;
float d150;
float d180;
//Libraries /////////////////////////////////////////////////////////////////////////////
#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(22, 24, 26, 28, 30, 32);
Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(A4,INPUT);
  pinMode(A5,OUTPUT);

  Serial.begin(9600);
  lcd.begin(16,2);
  servo.attach(3);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

}


void round1(){
  for(Time=0;Time<=180;Time=Time+30){
    servo.write(Time);
    digitalWrite(A5, LOW);
    delayMicroseconds(10);
    digitalWrite(A5, HIGH);
    delayMicroseconds(10);
    digitalWrite(A5, LOW);
    pingTravelTime=pulseIn(A4, HIGH);
    delay(25);
    Serial.println(distance);
    distance=velocity*pingTravelTime;
    d0=distance;
    delay(100);
    if(d0<13 and d0>0){
      servo.write(0);
      left();
      delay(250);
    }
    
    else{
      forward();
    }
  }
  
  ////////////////////////////////////////////  180 degrees finished sensing ////////////////////////////////////////////////////////
}
void stopped(int T){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(T);
}
void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void backward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void left(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//////////////////////////////////////////////// Moving Directions /////////////////////////////////////////////////////////////////


void loop() {
  // put your main code here, to run repeatedly:
  
  round1();
}
