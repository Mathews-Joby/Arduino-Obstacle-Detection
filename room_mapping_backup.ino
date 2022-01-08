#include <LiquidCrystal.h>
#include <Servo.h>

int pingTravelTime;
float velocity=0.016667;
float distance;
int i;
int Time;

// motor board

int ENA=5;
int ENB=6;
int IN1=7;
int IN2=8;
int IN3=9;
int IN4=11;



// values from 180 degrees

float d0;
float d30;
float d60;
float d90;
float d120;
float d150;
float d180;

//2nd round



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
  
  servo.write(0);
  
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



  if(d0<13 and d0>0){
    left();
    delay(250);
  }

  delay(80);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  servo.write(30);
  
  digitalWrite(A5, LOW);
  delayMicroseconds(10);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  pingTravelTime=pulseIn(A4, HIGH);
  delay(25);

  Serial.println(distance);
  distance=velocity*pingTravelTime;

  d30=distance;



  if(d30<13 and d30>0){
    left();
    delay(250);
  }
  delay(80);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  servo.write(60);
  
  digitalWrite(A5, LOW);
  delayMicroseconds(10);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  pingTravelTime=pulseIn(A4, HIGH);
  delay(25);

  Serial.println(distance);
  distance=velocity*pingTravelTime;

  d60=distance;



  if(d60<13 and d60>0){
    left();
    delay(250);
  }
  delay(80);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  servo.write(90);
  
  digitalWrite(A5, LOW);
  delayMicroseconds(10);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  pingTravelTime=pulseIn(A4, HIGH);
  delay(25);

  Serial.println(distance);
  distance=velocity*pingTravelTime;

  d90=distance;



  if(d90<13 and d90>0){
    left();
    delay(1000);
  }
  delay(80);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  servo.write(120);
  
  digitalWrite(A5, LOW);
  delayMicroseconds(10);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  pingTravelTime=pulseIn(A4, HIGH);
  delay(25);

  Serial.println(distance);
  distance=velocity*pingTravelTime;

  d120=distance;



  if(d120<13 and d120>0){
    right();
    delay(250);
  }
  delay(80);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  servo.write(150);
  
  digitalWrite(A5, LOW);
  delayMicroseconds(10);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  pingTravelTime=pulseIn(A4, HIGH);
  delay(25);

  Serial.println(distance);
  distance=velocity*pingTravelTime;

  d150=distance;



  if(d150<13 and d150>0){
    right();
    delay(250);
  }
  delay(80);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  servo.write(180);
  
  digitalWrite(A5, LOW);
  delayMicroseconds(10);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  digitalWrite(A5, LOW);
  pingTravelTime=pulseIn(A4, HIGH);
  delay(25);

  Serial.println(distance);
  distance=velocity*pingTravelTime;

  d180=distance;

  
  if(d180<13 and d180>0){
    right();
    delay(250);
  }
  

//  else{
//    lcd.setCursor(0,0);
//    lcd.print("moving");
//    lcd.clear();
//    forward();
//    delay(100);
//  }
  delay(80);
  ////////////////////////////////////////////  180 degrees finished sensing 1st round ////////////////////////////////////////////////////////

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


void loop() {
  // put your main code here, to run repeatedly:
  
  round1();
}
