#define PH A0 
#define DTS A6
#define do_duc A2  
#define DO A3 
#include "GravityTDS.h"
GravityTDS gravityTds;
const int stepPin = 7;
const int dirPin = 8;
const int e= 6;
const int CBT=5;
const int CBD=10;
int tam=0;
#include <LiquidCrystal_I2C_AvrI2C.h> 
LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 9
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
#define BLYNK_PRINT Serial 
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <avr/pgmspace.h>

SoftwareSerial SIM900(11, 12); // CHÂN TX NỐI VỚI CHÂN 11, CHÂN RX NỐI VỚI CHÂN 12
String textSMS=" "; // NỘI DUNG GỬI

/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
const byte NumberOfFields2 = 1;
int second, minute, hour, day, wday, month, year;

SoftwareSerial EspSerial(3, 2);
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
char auth[] = "44b7e03c80684cd9b566eb33f05fe7bd";
char ssid[] = "Thanh Dat 3G";
char pass[] = "thanhdatkhkt";

boolean a,b,c=0,d=1; 
float pHValuecu,pHValue,voltage_PH, do_duc_Value,voltage_do_duc,dts_Value,voltage_dts,nhiet_do,do_duc_Value_cu,do_Value;
float Vclear = 3.95;
#define VREF 5000
float averageVoltage;
#define MOTORB_1 13 //IN3
#define MOTORB_2 4  //IN4
#define MOTORA_1 0  //IN1
#define MOTORA_2 1  //IN2

void setup() {
//Serial.begin(9600);
SIM900.begin(9600);
gravityTds.setPin(DTS);
gravityTds.setAref(5.0);
gravityTds.setAdcRange(1024);
gravityTds.begin();
Wire.begin();
//setTime(11, 19, 00, 3, 25, 12, 18);
    
EspSerial.begin(ESP8266_BAUD);
Blynk.begin(auth, wifi, ssid, pass);  
lcd.begin();
lcd.backlight();
sensors.begin();
pinMode (stepPin, OUTPUT);
pinMode (dirPin, OUTPUT);
pinMode (e, OUTPUT);
pinMode (CBT, INPUT_PULLUP);
pinMode (CBD, INPUT_PULLUP);
digitalWrite(e,0);
digitalWrite(dirPin,1);
pinMode(MOTORA_1, OUTPUT);
pinMode(MOTORA_2, OUTPUT);
pinMode(MOTORB_1, OUTPUT);
pinMode(MOTORB_2, OUTPUT);
digitalWrite(MOTORA_1,LOW);
digitalWrite(MOTORA_2,LOW);
digitalWrite(MOTORB_1,LOW);
digitalWrite(MOTORB_2,LOW);
len();

}
BLYNK_WRITE(V10)
{
   a = param.asInt();
}
BLYNK_WRITE(V11)
{
  b = param.asInt();
}

// TIẾN
BLYNK_WRITE(V5) {
  int button = param.asInt(); // read button
  if (button == 1) 
  {
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else 
  {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}

// PHẢI
BLYNK_WRITE(V6) {
  int button = param.asInt(); // read button
  if (button == 1) 
  {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else 
  {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}

// TRÁI
BLYNK_WRITE(V8) {
  int button = param.asInt(); // read button
  if (button == 1) 
  {
    digitalWrite(MOTORA_1,HIGH);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
  else 
  {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}

// LÙI
BLYNK_WRITE(V7) {
  int button = param.asInt(); // read button
  if (button == 1) 
  {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,HIGH);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }
  else 
  {
    digitalWrite(MOTORA_1,LOW);
    digitalWrite(MOTORA_2,LOW);
    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}

void loop() 
{
Blynk.run();
readDS1307();
displaytime();
if(tam==1)
{

hien_thi_blynk();
tam=0;
}

if (a==1||(hour==6&&minute==0&&second==20)||(hour==15&&minute==0&&second==20)||(hour==17&&minute==0&&second==20)) 
{
 a=0;
 digitalWrite(e,0);
 digitalWrite(dirPin,1);
 len();
}
if (b==1||(hour==6&&minute==0&&second==0)||(hour==13&&minute==0&&second==0)||(hour==17&&minute==4&&second==0)) 
{
 Blynk.virtualWrite(V0, 0);
 Blynk.virtualWrite(V1, 0);
 Blynk.virtualWrite(V2, 0);
 Blynk.virtualWrite(V3, 0);
 Blynk.virtualWrite(V4, 0);
 b=0;
 digitalWrite(e,0);
 digitalWrite(dirPin,0);
 xuong();

}  
}


void len()
{
while(1)
{
 digitalWrite(stepPin,HIGH);
 Delay(2);
 digitalWrite(stepPin,LOW);
 Delay(2);
if(digitalRead(CBT)==0) 
{
  digitalWrite(e,1);
  break;
}
}
}

void xuong()
{
while(1)
{
 digitalWrite(stepPin,HIGH);
 Delay(2);
 digitalWrite(stepPin,LOW);
 Delay(2);
 if(digitalRead(CBD)==0) 
{
digitalWrite(e,1);
 unsigned long endTime = millis() + 3000;
 while(millis() < endTime)
 {
  Blynk.run();
  while(millis() < endTime){};
 }
 doc_cam_bien();
 tam=1;
 
 break;
}
}
}

void Delay(float delayTime)
{
 unsigned long endTime = millis() + delayTime;
 while(millis() < endTime)
 {
  while(millis() < endTime){};
 }
}
void doc_cam_bien()
{
 int so_PH, so_dd, so_dts;
 so_PH=analogRead(PH);
 so_dd=analogRead(do_duc);
 so_dts=analogRead(DTS);

 sensors.requestTemperatures();
 nhiet_do=sensors.getTempCByIndex(0);

 voltage_PH=(so_PH*5.0)/1023.0;
 
 pHValuecu=voltage_PH*3.5;
 if (pHValuecu <=7.0)
 {
  pHValue=voltage_PH*3.5;
 }
 else
 {
  pHValue=voltage_PH*3.5-1.85;
 }
 
 voltage_do_duc=(so_dd*5.0)/1024.0;
 do_duc_Value=100-(voltage_do_duc/Vclear)*100;
 if (do_duc_Value < 0)
 {
  do_duc_Value=0;
 }

 gravityTds.setTemperature(nhiet_do);
 gravityTds.update();
 dts_Value = gravityTds.getTdsValue();

 int analogBuffer = analogRead(DO);  
 averageVoltage = analogBuffer * 5.0/ 1023.0;
 do_Value =nhiet_do * averageVoltage*150/ 1127.6;
}

void hien_thi_blynk()
{
 lcd.setCursor(6,0);
 lcd.print(pHValue);
 lcd.setCursor(12,0);
 lcd.print(round(do_duc_Value));
 lcd.setCursor(15,0);
 lcd.print("%");
 lcd.setCursor(6,1);
 lcd.print(nhiet_do);
 lcd.setCursor(12,1);
 lcd.print(round(dts_Value));
 lcd.setCursor(0,1);
 lcd.print(do_Value);
 
 Blynk.virtualWrite(V0, pHValue);
 Blynk.virtualWrite(V1, round(do_duc_Value));
 Blynk.virtualWrite(V2, nhiet_do);
 Blynk.virtualWrite(V3, round(dts_Value));
 Blynk.virtualWrite(V4, do_Value);
 
 sendSMS(textSMS);  // GỬI TÍN HIỆU SMS
}
/* cài đặt thời gian cho DS1307 */
void setTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr)
{
 Wire.beginTransmission(DS1307);
 Wire.write(byte(0x00)); // đặt lại pointer
        Wire.write(dec2bcd(sec));
        Wire.write(dec2bcd(min));
        Wire.write(dec2bcd(hr));
        Wire.write(dec2bcd(wd)); // day of week: Sunday = 1, Saturday = 7
        Wire.write(dec2bcd(d)); 
        Wire.write(dec2bcd(mth));
        Wire.write(dec2bcd(yr));
        Wire.endTransmission();
}
int bcd2dec(byte num)
{
        return ((num/16 * 10) + (num % 16));
}
int dec2bcd(byte num)
{
        return ((num/10 * 16) + (num % 10));
}

void readDS1307()
{
        Wire.beginTransmission(DS1307);
        Wire.write((byte)0x00);
        Wire.endTransmission();
        Wire.requestFrom(DS1307, NumberOfFields);
        
        second = bcd2dec(Wire.read() & 0x7f);
        minute = bcd2dec(Wire.read() );
        hour   = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
        wday   = bcd2dec(Wire.read() );
        day    = bcd2dec(Wire.read() );
        month  = bcd2dec(Wire.read() );
        year   = bcd2dec(Wire.read() );
        //year += 2000;    
}
void displaytime()
{
 conveter(0,0,hour);
 lcd.setCursor(2,0);
 lcd.print(":");
 conveter(3,0,minute);
 //conveter(0,1,day);
 //lcd.setCursor(2,1);
 //lcd.print("/");
 //conveter(3,1,month);
}
void conveter(byte where1,byte where2, int timer)
{
  if (timer < 10) {
    lcd.setCursor(where1, where2);
    lcd.print("0");
    lcd.setCursor((where1+1), where2);
    lcd.print(timer);
  } else {
    lcd.setCursor(where1, where2);
    lcd.print(timer);
  }
}
void setup ();
{
  if ( void sendSMS(string message));
  else rf (63 DEVICE_REMOTE_WAKEUP)
  int six=0 ;
  if(six <= 600);
  int recsbe=65 ;
  if (recsbe ==0 );
  then six == 0 if v ==3
void sendSMS(String message)
{
 SIM900.println("AT+CMGF=1");
 delay(1000);
 SIM900.println("AT+CMGS=\"+84799896871\"\r");
 delay(1000);
 SIM900.println("KET QUA DO DUOC:");
 SIM900.println("pH: "+String(pHValue));
 SIM900.println("DO DUC: "+String(round(do_duc_Value))+"%");
 SIM900.println("NHIET DO: "+String(nhiet_do)+"'C");
 SIM900.println("TDS: "+String(round(dts_Value))+"ppm");
 SIM900.println("DO: "+String(do_Value)+"mg/l");
 delay(100);
 SIM900.println((char)26);
 delay(1000);
}
