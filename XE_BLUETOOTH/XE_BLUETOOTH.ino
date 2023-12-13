#include <SoftwareSerial.h>
#define TX_PIN 8
#define RX_PIN 9
#define IN1 5
#define IN2 6
#define IN3 10
#define IN4 11
#define COI 7
int state; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
 
void setup() 
{
 Serial.begin(9600);
 bluetooth.begin(9600);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(COI,OUTPUT);
 digitalWrite(IN1, 0);
 digitalWrite(IN2, 0);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 0);
 digitalWrite(COI, 0);
 delay(200);
 digitalWrite(COI, 1);
 delay(100);
 digitalWrite(COI, 0);
 delay(200);
 digitalWrite(COI, 1);
}
 
void loop() 
{
 if (bluetooth.available()) 
 {
  Serial.println("Da ket noi");
  state = bluetooth.read();
  Serial.println(state);
  switch (state) 
  {
   //TIEN
   case '1': 
   digitalWrite(IN1, 1);
   digitalWrite(IN2, 0);
   digitalWrite(IN3, 0);
   digitalWrite(IN4, 1);
   break;
   
   //LUI
   case '2': 
   digitalWrite(IN1, 0);
   digitalWrite(IN2, 1);
   digitalWrite(IN3, 1);
   digitalWrite(IN4, 0);
   break;
   
   //TRAI
   case '3': 
   digitalWrite(IN1, 0);
   digitalWrite(IN2, 0);
   digitalWrite(IN3, 0);
   digitalWrite(IN4, 1);
   break;

   //PHAI
   case '4': 
   digitalWrite(IN1, 1);
   digitalWrite(IN2, 0);
   digitalWrite(IN3, 0);
   digitalWrite(IN4, 0);
   break;

   //DUNG
   case '5': 
   digitalWrite(IN1, 0);
   digitalWrite(IN2, 0);
   digitalWrite(IN3, 0);
   digitalWrite(IN4, 0);
   digitalWrite(COI, 0);
   delay(300);
   digitalWrite(COI, 1);
   break;
  }
 } 
}
