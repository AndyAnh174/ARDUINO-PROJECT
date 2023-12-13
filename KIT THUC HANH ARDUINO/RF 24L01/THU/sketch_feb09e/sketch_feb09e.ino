#include <SPI.h>
#include "RF24.h"
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // địa chỉ phát
RF24 radio(9,10);//thay 10 thành 53 với mega
char msg[10];
const int led = 5;
int led_st = 0;
char text[10] = ""; 
void setup(){
  Serial.begin(9600);
  radio.begin();                     
  radio.setAutoAck(1);              
  radio.setDataRate(RF24_1MBPS);    // Tốc độ dữ liệu
  radio.setChannel(10);               // Đặt kênh
  radio.openReadingPipe(1,pipe);     
  radio.startListening();            
  pinMode(led, OUTPUT);
 digitalWrite(5,1);
 delay(1000);
 digitalWrite(5,0);
}
 
void loop(){
 if (radio.available()){
    while (radio.available()){
    radio.read(&text, sizeof(text));
    Serial.println(text);

    }
   }
    if(String(text)=="ENTER") digitalWrite(5,1);
    else if(String(text)=="ESC") digitalWrite(5,0);
    
}
