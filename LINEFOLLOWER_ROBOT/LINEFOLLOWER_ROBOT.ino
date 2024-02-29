int l=14;
int m=15;
int r=16;
int rp=3;
int rn=5;
int lp=6;
int ln=9;
void forward()
{
  analogWrite(rp,80);
  digitalWrite(rn,LOW);
  analogWrite(lp,80);
  digitalWrite(ln,LOW);
  Serial.println("forward");
  
  
}
void right()
{
  digitalWrite(rp,LOW);
  digitalWrite(rn,LOW);
  analogWrite(lp,70);
  digitalWrite(ln,LOW);
  Serial.println("right");


}

void left()
{
  analogWrite(rp,70);
  digitalWrite(rn,LOW);
  analogWrite(lp,0);
  digitalWrite(ln,LOW);
  Serial.println("left");

  
}

void stopp()
{
  analogWrite(rp,0);
  analogWrite(rn,0);
  analogWrite(lp,0);
  analogWrite(ln,0);
  Serial.println("stop");

}
void sf()

{ analogWrite(rp,0);
analogWrite(rn,0);
analogWrite(lp,0);
analogWrite(ln,0);
  delay(1000);
   analogWrite(rp,60);
  digitalWrite(rn,LOW);
  analogWrite(lp,60);
  digitalWrite(ln,LOW);
  delay(2000);
}


int a,b,c;



void setup() {
  // put your setup code here, to run once:
pinMode(l,INPUT);
pinMode(m,INPUT);
pinMode(r,INPUT);
pinMode(rp,OUTPUT);
pinMode(rn,OUTPUT);
pinMode(lp,OUTPUT);
pinMode(ln,OUTPUT);
Serial.begin(9600);

}

void loop() {
  a=digitalRead(l);
  b=digitalRead(m);
  c=digitalRead(r);
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  
  if(a==0&&b==1&&c==0)
  {forward();
  }
  else if (a==1&&b==1&&c==0)
  {sf();
  }
  else if(a==0&&b==0&&c==1)
  {
    right();
  }
  
  else if(a==1&&b==0&&c==0)
  {
    left();
  }
  else if (a==1&&b==1&&c==1)
  {
    stopp();
    delay(5000);
  
  }  
}
