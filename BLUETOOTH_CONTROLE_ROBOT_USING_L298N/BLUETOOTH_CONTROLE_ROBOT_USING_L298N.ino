int i1=6;
int i2=9;
int i3=10;
int i4=11;
int state;
void setup()
{
  pinMode(i1,OUTPUT);
  pinMode(i2,OUTPUT);




  
  pinMode(i3,OUTPUT);
  pinMode(i4,OUTPUT);
 Serial.begin(9600);
}
void loop()
{
  while(Serial.available()>0)
  state=Serial.read();
  if(state=='2')
  {
    digitalWrite(i1,LOW);
    analogWrite(i2,80);
    digitalWrite(i3,LOW);
    analogWrite(i4,80);
    Serial.println("back");
    delay(1000);
  }
  if(state=='1')
  {
   
    analogWrite(i1,80);
    digitalWrite(i2,LOW);
    analogWrite(i3,80);
    digitalWrite(i4,LOW);
    
    delay(1000);

  Serial.println("forword");
  }
  
   if(state=='3')
  {
    analogWrite(i1,80);
    digitalWrite(i2,LOW);
    digitalWrite(i3,LOW);
    digitalWrite(i4,LOW);
    delay(1000);
    Serial.println("right");
    
  }
   if(state=='4')
  {
    digitalWrite(i1,LOW);
    digitalWrite(i2,LOW);
    analogWrite(i3,80);
    digitalWrite(i4,LOW);
    delay(1000);
    Serial.println("left");
  }
   if(state=='5')
  {
    digitalWrite(i1,LOW);
    digitalWrite(i2,LOW);
    digitalWrite(i3,LOW);
    digitalWrite(i4,LOW);
    Serial.println("stop");
  }
}
