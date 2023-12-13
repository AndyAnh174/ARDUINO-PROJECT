//Include thư viện
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TimerOne.h>
#define LAT 4
#define CK 7
#define DA 8
int nghin, tram, chuc, donvi,i;
const byte SEG[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
const byte LED[]={0xF1,0xF2,0xF4,0xF8};
const byte ht[]={0x9C,0xC6};
// Chân nối với Arduino
#define ONE_WIRE_BUS 2
//Thiết đặt thư viện onewire
OneWire oneWire(ONE_WIRE_BUS);
//Mình dùng thư viện DallasTemperature để đọc cho nhanh
DallasTemperature sensors(&oneWire);
 
void setup() {
  // put your setup code here, to run once:
pinMode(LAT,OUTPUT);
pinMode(CK,OUTPUT);
pinMode(DA,OUTPUT);
Serial.begin(9600);
sensors.begin();
Timer1.initialize(1000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
Timer1.attachInterrupt( timerIsr );
}
void timerIsr()
{
hienthi(chuc,0);
hienthi(donvi,1);
hienthido(0,2);
hienthido(1,3);
}
void loop() {
float t;                              
sensors.requestTemperatures();  
Serial.print("Nhiet do: ");
t=sensors.getTempCByIndex(0);
i=(int) t;
Serial.println(i); // vì 1 ic nên dùng 0
nghin=i/1000;
tram=(i%1000)/100;
chuc=((i%1000)%100)/10;
donvi=((i%1000)%100)%10;
}
void hienthi(byte so, byte L)
{
  digitalWrite(LAT,0);
  shiftOut(DA,CK,MSBFIRST,SEG[so]);
  shiftOut(DA,CK,MSBFIRST,LED[L]);
  digitalWrite(LAT,1);
}
void hienthido(byte so, byte L)
{
  digitalWrite(LAT,0);
  shiftOut(DA,CK,MSBFIRST,ht[so]);
  shiftOut(DA,CK,MSBFIRST,LED[L]);
  digitalWrite(LAT,1);
}


