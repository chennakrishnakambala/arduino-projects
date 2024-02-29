char state; //Will hold the incoming character from the  Serial Port.


 int led = 13;
 
 
 void setup()
 {
 // prepare the digital output pins
 pinMode(led, OUTPUT);
 
 digitalWrite(led, LOW);

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
 
 while(Serial.available() >0)
 {
 state=Serial.read(); 
       if (state=='A')
        {
          delay(10);
                  digitalWrite(led, HIGH);
                    delay(1000);
         
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"8008482832\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("Power ON");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                    }
                       else if (state=='B')
                          {
                          digitalWrite(led, LOW);
                          delay(1000);
                      // Serial.println("AT+CMGD=1,4");                   //Delete all message
                     //     delay(500);
                          Serial.println("AT+CMGF=1");
                          delay(500);
                          Serial.println("AT+CMGS=\"8008482832\"");//Change the receiver phone number
                          delay(500);
                          Serial.print("Power OFF");    //the message you want to send
                          delay(500);
                          Serial.write(26);
                          delay(500);
                          }
                  
       
             }
             
              Serial.println("AT+CMGD=1,4");
        }
          
    
