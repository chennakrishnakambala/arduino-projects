int red_led=13;

int green_led=11;

dht DHT;
int buzz=13;

int gas_value;

int gas_avalue;
#define DHT11_PIN 7
int sensorThres=410;
#include <dht.h>
void setup()

{

pinMode(red_led,OUTPUT);

pinMode(buzz,OUTPUT);

pinMode(green_led,OUTPUT);

pinMode(A0,INPUT);

Serial.begin(9600);

}

void loop()

{

gas_avalue=analogRead(A0);

if (gas_avalue > sensorThres)

{

digitalWrite(red_led, HIGH);

digitalWrite(green_led, LOW);

digitalWrite( buzz, HIGH);

Serial.println("DANGER!!!!");

Serial.println(gas_avalue);

}

if (gas_avalue < sensorThres)


{

digitalWrite(red_led, LOW);

digitalWrite(green_led, HIGH);

digitalWrite( buzz, LOW);

Serial.println("NO LEAKAGE");

Serial.println(gas_avalue);

}

int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);



delay(100);

}
