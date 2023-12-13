#include <SoftwareSerial.h>
#include <HCSR04.h>
UltraSonicDistanceSensor distanceSensor(24, 23);
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(11, 10); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
int strobePin = 12; 
int dataPin = 51;   //Pin connected to Data (pin 2) of 4094
int clockPin = 52;  //Pin connected to Clock (pin 3) of 4094
byte segChar[] = {0x05, 0x3f, 0x46, 0x16, 0x3c, 0x94, 0x84, 0x37, 0x04, 0x14, 0xfe,0x00,0xff,0xc5};
byte segCharc[] = {0xc5};
byte segChardot[] ={0x01, 0x3B, 0x42, 0x12, 0x38, 0x90, 0x80, 0x33, 0x00, 0x10, 0xfa};  // font 3x4 co dau cham.
int nghin, tram, chuc, donvi,i,thapphan;

#define CB            15     //cb xac dinh co nguoi
#define CBT           16     //cb hong ngoai rua tay
#define LENREMOTE     4      //nhan di len
#define XONGREMOTE    5      //nhan di xuong
#define DOREMOTE      6      //nha do nhiet
#define CTHT          17     //cong tac hanh trinh tren
#define CHEDODK       14     //xac dinh che do su dung "cong tac"
#define BOM           2      //may bom
#define LEN           8      //nang can do len
#define XUONG         9      //ha can do xuong
#define LEDBAO        22     //led bao dung vi tri dung

float nd;
float kcm;
float kcd;
int state,gt,k=0,cbr=0,GIAOTIEP=1,gh=0; 

void setup() 
{
 Serial.begin(9600);
 Serial1.begin(9600);
 mySoftwareSerial.begin(9600);
 Serial.println();
 Serial.println(F("DFRobot DFPlayer Mini Demo"));
 Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
 if (!myDFPlayer.begin(mySoftwareSerial)) 
 {
  Serial.println(F("Unable to begin:"));
  Serial.println(F("1.Please recheck the connection!"));
  Serial.println(F("2.Please insert the SD card!"));
  while(true);
 }
 Serial.println(F("DFPlayer Mini online."));
 myDFPlayer.setTimeOut(500);
 myDFPlayer.volume(20);
 myDFPlayer.volumeUp();
 myDFPlayer.volumeDown();
 myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
 Serial.println("Adafruit MLX90614 test");  
 mlx.begin(); 
 while (! Serial) 
  {
   delay(1);
  }
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) 
  {
   Serial.println(F("Failed to boot VL53L0X"));
   while(1);
  }
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));  
  
 pinMode(LENREMOTE,INPUT_PULLUP);
 pinMode(XONGREMOTE,INPUT_PULLUP);
 pinMode(DOREMOTE,INPUT_PULLUP);;
 pinMode(CBT,INPUT_PULLUP);
 pinMode(CTHT,INPUT_PULLUP);
 pinMode(CB,INPUT_PULLUP);
 pinMode(XUONG,OUTPUT);
 pinMode(LEN,OUTPUT);
 pinMode(BOM,OUTPUT);
 pinMode(LEDBAO,OUTPUT);
 digitalWrite(BOM, 0);
 digitalWrite(LEN, 1);
 digitalWrite(XUONG, 1);
 digitalWrite(LEDBAO, 1);
 pinMode(strobePin, OUTPUT);
 pinMode(clockPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
 gt=digitalRead(CHEDODK);
 if (gt==0)
 {
  myDFPlayer.play(2);
 }
 if (gt==1)
 {
  myDFPlayer.play(3);
 }
}
 
void loop() 
{ 
 gt=digitalRead(CHEDODK);
 kcd=distanceSensor.measureDistanceCm();
 //Serial.println(cbr);
 nd=0;
 VL53L0X_RangingMeasurementData_t measure;
 lox.rangingTest(&measure, false);
 //Serial.println(measure.RangeMilliMeter);
 if(gt==0) 
 {
  dieukhienremote();
  ruatay(); 
 }
 if(gt==1)
 {
  kcmat();
  dieukhietudong();
  ruatay(); 
 }
}

void dieukhienremote()
{ 
 kcmat();
 if(digitalRead(LENREMOTE)==1) 
 {
  digitalWrite(LEN, 0);
  digitalWrite(XUONG, 1);
  if(digitalRead(CTHT)==0) 
  {
   digitalWrite(LEN, 1);
   delay(2000);
   digitalWrite(XUONG, 0);
   delay(1000);
   digitalWrite(XUONG, 1);
  }
 }
 else
 {                                              
  digitalWrite(LEN, 1);
 } 
 if(digitalRead(XONGREMOTE)==1) 
 {
  digitalWrite(XUONG, 0);
  digitalWrite(LEN, 1);
 }
 else
 {
  digitalWrite(XUONG, 1);
 }
 if (gt==0&kcm<=80&kcm>=60)
 {
  donhietdo();
  hienthiled7doan(); // hien thi led 7 doan
  cbr=1;
 }
 if(digitalRead(DOREMOTE)==1) 
 {
  donhietdo();
  hienthiled7doan(); // hien thi led 7 doan
  cbr=1;
 }
}

void dieukhietudong()
{
 kcmat();
 if (digitalRead(CB)==1)
 {
  digitalWrite(LEN, 0);
  
  digitalWrite(XUONG, 1);
  if(digitalRead(CTHT)==0) 
  {
   digitalWrite(LEN, 1);
   delay(1000);
   digitalWrite(XUONG, 0);
   delay(1000);
   digitalWrite(XUONG, 1);
   while(1)
   {
    if(digitalRead(CB)==0) 
    {                              
     break;
    } 
   }
  }
 }
 if (digitalRead(CB)==0)
 {
  digitalWrite(XUONG, 0);
  digitalWrite(LEN, 1);
  kcd=distanceSensor.measureDistanceCm();
  if((kcd>24.0)&(kcd<26.0))
  {
   digitalWrite(XUONG, 1);
   delay(1000);
   donhietdo();
   hienthiled7doan(); // hien thi led 7 doan 
   cbr=1; 
   while(1)
   {
    if(digitalRead(CB)==1)
    {
     break;
    }
   }
  }
 }
}

void kcmat()
{
 VL53L0X_RangingMeasurementData_t measure;
 lox.rangingTest(&measure, false);
 kcm=measure.RangeMilliMeter;
 Serial.println(kcm);
 if((kcm<=70)&(kcm>=50))
 {
  digitalWrite(LEDBAO, 0);
 }
 else
 {
  digitalWrite(LEDBAO, 1);
 }
}

void donhietdo()
{
  hienthic(14); 
  hienthi(0); 
  hienthidaucham(0);
  hienthi(0);
  delay(500);
  int j;
  for (j=1;j<=30;j=j+1)
  {
   nd=mlx.readObjectTempC();
  }
  if ((mlx.readObjectTempC()>=34.0)&(mlx.readObjectTempC()<34.6))
  {
    nd=mlx.readObjectTempC()+2.1;
  }
  if ((mlx.readObjectTempC()>=34.6)&(mlx.readObjectTempC()<35.0))
  {
    nd=mlx.readObjectTempC()+1.8;
  }
  if ((mlx.readObjectTempC()>=35.0)&(mlx.readObjectTempC()<35.6))
  {
    nd=mlx.readObjectTempC()+1.1;
  }
  if ((mlx.readObjectTempC()>=35.6)&(mlx.readObjectTempC()<36.0))
  {
    nd=mlx.readObjectTempC()+0.8;
  }
  Serial1.print(nd*100);
}

void ruatay()
{
 if ((digitalRead(CBT)==1)&(cbr==1)) 
 {
  while(1)
  {
   if ((digitalRead(CBT)==0)&(cbr==1)) 
   {
    cbr=0;
    digitalWrite(BOM,1);
    delay(300);
    digitalWrite(BOM,0);
    myDFPlayer.play(1); 
    break;
   }
  }
 }
}

void hienthiled7doan()
{
 i=nd*100;
 chuc=((i%1000)%100)/10;
 donvi=((i%1000)%100)%10;
 nghin=i/1000;
 tram=(i%1000)/100;
 Serial.println(nghin);
 Serial.println(tram);
 Serial.println(chuc);
 Serial.println(donvi);
 hienthic(14); 
 hienthi(chuc); 
 hienthidaucham(tram);
 hienthi(nghin);
}

void hienthi(unsigned char so) // hiển thị bên phải --> ở giữa -- > bên trái
{
 digitalWrite(strobePin, LOW);
 shiftOut(dataPin, clockPin, MSBFIRST,segChar[so]);   // hien thi ben trai
 digitalWrite(strobePin, HIGH);
}

void hienthidaucham(unsigned char so) // hiển thị bên phải --> ở giữa -- > bên trái
{
 digitalWrite(strobePin, LOW);
 shiftOut(dataPin, clockPin, MSBFIRST, segChardot[so]);   // hien thi ben trai
 digitalWrite(strobePin, HIGH);
}

void hienthic(unsigned char so) // hiển thị bên phải --> ở giữa -- > bên trái
{
 digitalWrite(strobePin, LOW);
 shiftOut(dataPin, clockPin, MSBFIRST, segCharc[so]);   // hien thi ben trai
 digitalWrite(strobePin, HIGH);
}
