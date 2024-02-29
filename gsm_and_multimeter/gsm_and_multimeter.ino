char inchar; //Willhold the incoming character from the  Serial Port.
 int led1 = 13;
 int red=4;
 int green=5;
 int volt;
 float voltage;
 void setup()
 {
 
 pinMode(led1, OUTPUT);
 pinMode(red, OUTPUT);
 digitalWrite(green,OUTPUT);
 digitalWrite(led1, LOW);
 Serial.begin(9600);
 Serial.print("pin state low\n");
 delay(3000); // give time for GSM module to register on network.
 Serial.println("AT+CMGF=1"); // set SMS mode to text
 delay(200);
 Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt 
 delay(200);
 }
 void loop() 
 {
 //If #a1b1c1d1 comes as sms, all led's should light up.
 volt= analogRead(A0);
  voltage =volt*(5.0 * 11/1024 );
  Serial.print("Voltage = ");
  Serial.print(voltage);
  Serial.println("V");
  delay(1000);
 if(Serial.available() >0)
 {
 inchar=Serial.read(); 
       if (inchar=='#')
        {
            delay(10); 
            
            inchar=Serial.read(); 
            //first led
            if (inchar=='a')//closed
             {
               delay(10);
               inchar=Serial.read();
               if (inchar=='0')//closed
                   {
                    digitalWrite(led1, LOW);
                    delay(1000);
                    
                    Serial.print("Relay 1 LOW\n");
                     delay(1000);
                   Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                 
                    delay(500);
                    Serial.println("AT+CMGS=\"8008482832\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("Power OFF");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                    }
                       else if (inchar=='1')
                          {
                          digitalWrite(led1, HIGH);
                          delay(1000);
     
                          Serial.print("Relay 1 HIGH\n");
                           delay(1000);
                       Serial.println("AT+CMGD=1,4");                   //Delete all message
                          delay(500);
                          Serial.println("AT+CMGF=1");
                          delay(500);
                          Serial.println("AT+CMGS=\"8008482832\"");//Change the receiver phone number
                          delay(500);
                          Serial.print("Power ON");    //the message you want to send
                          delay(500);
                          Serial.write(26);
                          delay(500);
                          }
                  
        delay(10);
        
             }
              Serial.println("AT+CMGD=1,4");
        }
          
    }
    if(voltage>11.9)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
     Serial.println("AT+CMGF=1");
    delay(500);
    Serial.println("AT+CMGS=\"8008482832\"");
    delay(500);
    Serial.print("POWER CAME");
    delay(500);
    Serial.write(26);
    delay(500);
    
  }
  if(voltage<10.5)
  {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    Serial.println("AT+CMGF=1");
    delay(500);
    Serial.println("AT+CMGS=\"8008482832\"");
    delay(500);
    Serial.print("POWER GONE");
    delay(500);
    Serial.write(26);
    delay(500);
   
  }

}
