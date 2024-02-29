
#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Servo.h>
#define M1 4
#define M2 5
Servo servo_1;
/* Example code for the Adafruit TCS34725 breakout library */ 
 

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
 
void setup(void) {
Serial.begin(9600);
servo_1.attach(9);
pinMode(M1 , OUTPUT);
pinMode(M2 , OUTPUT); 
if (tcs.begin()) 
{
Serial.println("Found sensor");
} 
else
{
Serial.println("No TCS34725 found ... check your connections");
while (1);
}
 
// Now we're ready to get readings!
}
 
void loop(void) {
uint16_t r, g, b, c, colorTemp, lux;
 
tcs.getRawData(&r, &g, &b, &c);
colorTemp = tcs.calculateColorTemperature(r, g, b);
lux = tcs.calculateLux(r, g, b);

Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
Serial.println(" ");

  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
 if(b > g && g > r)
{
digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  delay(3000);
  Serial.println("BLUE");
  servo_1.write(50);
   digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
 delay(5000);

}


if(g > r && r > b)
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  delay(3000);
  servo_1.write(90);
  Serial.println("GREEN");
   digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
 delay(5000);

}

if( r > b && b > g)
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  delay(3000);
  servo_1.write(130);
  Serial.println("RED");
   digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  delay(5000);

}

 
}
