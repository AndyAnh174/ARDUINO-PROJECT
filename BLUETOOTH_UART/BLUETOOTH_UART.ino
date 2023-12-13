#include <SoftwareSerial.h>
#define TX_PIN 11
#define RX_PIN 10
#define RELAY  5
int state; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
 
void setup() 
{
 Serial.begin(9600);
 bluetooth.begin(9600);
 pinMode(RELAY,OUTPUT);
 digitalWrite(RELAY, 0);
}
 
void loop() 
{
 if (bluetooth.available()) 
 {
  state = bluetooth.read();
  Serial.println(state);
  switch (state) 
  {
   case '1': //BẬT
   digitalWrite(RELAY, 1);
   break;
   case '2': //TẮT
   digitalWrite(RELAY, 0);
   break;
  }
 } 
}
