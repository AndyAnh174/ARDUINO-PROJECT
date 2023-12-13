#include <stdlib.h>  
#include <SoftwareSerial.h>
#include <Wire.h>
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  g;
int hour, minute;
int rx_data1;
char rx_data;
String storedData = "";
String storedData1 = "";
SoftwareSerial mySerial(11, 10); // RX = pin D2, TX = pin D3 RX trc TX sau
unsigned char LED_0F[] = 
{// 0	 1	  2	   3	4	 5	  6	   7	8	 9	  A	   b	C    d	  E    F    -
0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x8C,0xBF,0xC6,0xA1,0x86,0xFF,0xbf
};
unsigned char LED_ghj[] = 
{// 0   1    2    3      4    5    6    7    8   9    A    b  C    d    E    F    -
0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10
};
unsigned char LED[8];
int SCLK = 4;
int RCLK = 3;
int DIO =  2;
#define S1 5
int gt1=0;

void setup ()
{
 rtc.begin();
 Wire.begin();
 pinMode(SCLK,OUTPUT);
 pinMode(RCLK,OUTPUT);
 pinMode(DIO,OUTPUT);
 pinMode(S1,INPUT_PULLUP);
 //rtc.setTime(15,03, 0);
 mySerial.begin(9600);
 Serial.begin(9600);
}

void loop()
{
 g = rtc.getTime();
 hour=g.hour;
 minute=g.min;
 if(mySerial.available())
 {
  while(mySerial.available())  
  {
   rx_data = mySerial.read(); 
   storedData += rx_data;
   Serial.println(storedData);
   ht();
   LED8_Display ();
  }
 }
 if(storedData.length() >0)  
 {
  storedData1 = storedData;
  storedData="";
  rx_data1=storedData1.toInt();
 }
 ht();
 LED8_Display ();   
 }
 
void ht()
{
 LED[7]=hour/10;
 LED[6]=hour%10;
 LED[5]=minute/10;
 LED[4]=minute%10;
      
 LED[3]=rx_data1/1000;
 LED[2]=(rx_data1%1000)/100;
 LED[1]=((rx_data1%1000)%100)/10;
 LED[0]=(11+1);
}

void LED8_Display (void)
{
 unsigned char *led_table;
 unsigned char i;
 led_table = LED_0F + LED[0];
 i = *led_table;
 LED_OUT(i);      
 LED_OUT(0x01);    
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_0F + LED[1];
 i = *led_table;
 LED_OUT(i);   
 LED_OUT(0x02);    
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_ghj + LED[2];
 i = *led_table;
 LED_OUT(i);     
 LED_OUT(0x04);  
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_0F + LED[3];
 i = *led_table;
 LED_OUT(i);     
 LED_OUT(0x08);
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_0F + LED[4];
 i = *led_table;
 LED_OUT(i);     
 LED_OUT(0x10);    
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_0F + LED[5];
 i = *led_table;
 LED_OUT(i);   
 LED_OUT(0x20);    
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_ghj + LED[6];
 i = *led_table;
 LED_OUT(i);     
 LED_OUT(0x40);  
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
 led_table = LED_0F + LED[7];
 i = *led_table;
 LED_OUT(i);     
 LED_OUT(0x80);        
 digitalWrite(RCLK,LOW);
 digitalWrite(RCLK,HIGH);
}
    
void LED_OUT(unsigned char X)
{
 unsigned char i;
 for(i=8;i>=1;i--)
 {
  if (X&0x80) 
  {
   digitalWrite(DIO,HIGH);
  }  
  else 
  {
   digitalWrite(DIO,LOW);
  }
 X<<=1;
 digitalWrite(SCLK,LOW);
 digitalWrite(SCLK,HIGH);
 }
}
