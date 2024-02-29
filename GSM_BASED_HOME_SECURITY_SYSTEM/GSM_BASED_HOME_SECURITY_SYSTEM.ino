int pir;
int gas;
int fire;
 void setup()  
 {  
 Serial.begin(9600);  
 
 Serial.println("AT+CMGF=1"); // set SMS mode to text
 delay(200);
 Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt 
 delay(200);
 }  
 void loop()   
 {  
 pir = digitalRead(4); // pir sensor output pin connected  
 Serial.println(pir); // see the value in serial monitor in Arduino IDE  
 gas = digitalRead(8);
 Serial.println(gas);
 fire = digitalRead(10);
 Serial.println(fire);

 if(pir == 0 )  
{  
  Serial.println("ATD+918008482832;");
 delay(500);
 } 
 if(gas == 1)
 {
  Serial.println("AT+CMGF=1");
    delay(500);
    Serial.println("AT+CMGS=\"8008482832\"");
    delay(500);
    Serial.print("GAS DETECTED");
    delay(500);
    Serial.write(26);
    delay(500);
 }
 if(fire == 0)
 {
    Serial.println("AT+CMGF=1");
    delay(500);
    Serial.println("AT+CMGS=\"8008482832\"");
    delay(500);
    Serial.print("FIRE DETECTED");
    delay(500);
    Serial.write(26);
    delay(500);
 }
  
 }
