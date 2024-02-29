#include<Servo.h>
Servo servo1;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
int ir = 10;
int fp = 2;
int fn = 3;
int bp = 4;
int bn = 5;
int ledr = 6;
int ledg = 11;


 
void setup()
{
  servo1.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir,INPUT);      
  pinMode(fp, OUTPUT);
  pinMode(fn, OUTPUT);
  pinMode(bp, OUTPUT);
  pinMode(bn, OUTPUT);
  pinMode(ledr,OUTPUT);
  pinMode(ledg, OUTPUT);
}



void loop()
{
  irs();
  ultra();
  top_open();
}
void top_open(){
    if(distance <= 10){
    digitalWrite(ledg, HIGH);
    digitalWrite(ledr, LOW);
    servo1.write(90);
    delay(15000);
   }
   else  {
    servo1.write(0);
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, HIGH);
    delay(15000);
    digitalWrite(ledr, LOW);
    digitalWrite(ledg, HIGH);
    
   }
}
void irs(){
  ir = (10);
  if(ir==0){
    stop();
    Serial.print("stop");
   }
   else if (ir==1){
    forward();
    Serial.print("forward");
   }
   
}
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  }


void stop(){
  digitalWrite(fp,LOW);
  digitalWrite(fn,LOW);
  digitalWrite(bp,LOW);
  digitalWrite(bn,LOW);
}


void forward(){
  analogWrite(fp,70);
  digitalWrite(fn,LOW);
  analogWrite(bp,60);
  digitalWrite(bn,LOW);
  
}
