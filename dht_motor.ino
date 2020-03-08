#include <dht.h>

dht DHT;

const int  DHT11_PIN=7;
const int   FAN_DC_MOTOR_PIN=5;

char c='0';

void setup(){
  pinMode(FAN_DC_MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("{\"temp\":");Serial.print(DHT.temperature);Serial.print(",");
  Serial.print("\"hum\":");Serial.print(DHT.humidity);Serial.println("}");
  //Serial.println();

  if (Serial.available()>0) {
    c = Serial.read();
    if(c=='1')  analogWrite(FAN_DC_MOTOR_PIN, 200);
    if(c=='0')  analogWrite(FAN_DC_MOTOR_PIN, 0);
  }
 
  delay(2000);
}
