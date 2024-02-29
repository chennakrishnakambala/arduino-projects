//Receiver code 

//all the best

#include

SoftwareSerial mybt(2,3);

char m=0,n=0;



void setup() {

pinMode(10, OUTPUT);

pinMode(11, OUTPUT);

pinMode(12, OUTPUT);

pinMode(13, OUTPUT);

Serial.begin(9600);

mybt.begin(9600);

}



void loop() {

if(mybt.available()>0)

{

m= mybt.read();

Serial.println(m);

if(m=='F')



{

digitalWrite(10, HIGH);

digitalWrite(11, LOW);

digitalWrite(12, HIGH);

digitalWrite(13, LOW);



}



else if(m=='B')



{

digitalWrite(10, LOW);

digitalWrite(11, HIGH);

digitalWrite(12, LOW);

digitalWrite(13, HIGH);



}



else if(m=='R')



{

digitalWrite(10, LOW);

digitalWrite(11, HIGH);

digitalWrite(12, HIGH);

digitalWrite(13, LOW);



}

else if(m=='L')



{

digitalWrite(10, HIGH);

digitalWrite(11, LOW);

digitalWrite(12, LOW);

digitalWrite(13, HIGH);



}



else if(m=='N')



{

digitalWrite(10, LOW);

digitalWrite(11, LOW);

digitalWrite(12, LOW);

digitalWrite(13, LOW);



}

else



{

digitalWrite(10, LOW);

digitalWrite(11, LOW);

digitalWrite(12, LOW);

digitalWrite(13, LOW);



}



} }
