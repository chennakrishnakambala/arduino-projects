//transmitter code 

//all the best

#include

SoftwareSerial mybt(2,3);

int m=0, n=0;



void setup() {



pinMode(A0, INPUT);

pinMode(A1, INPUT);

mybt.begin(9600);

Serial.begin(9600);

}



void loop() {

m = analogRead(A0);

n = analogRead(A1);



//Serial.println(m);

//delay(500);

//Serial.println(n);

//delay(500);



if(n>=375)



{

mybt.write("F");

Serial.println("F");



}



else if(n<=320) { mybt.write("B"); Serial.println("B"); } 


else if(m>=375)

{

mybt.write("R");

Serial.println("R");



}



else if(m<=315)

{

mybt.write("L");

Serial.println("L");



}



else

{

mybt.write("N");

Serial.println("N");



}


}
