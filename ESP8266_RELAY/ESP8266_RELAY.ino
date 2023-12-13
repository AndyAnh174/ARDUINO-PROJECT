#include <Wire.h>
/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
const byte NumberOfFields2 = 1;
int second, minute, hour, day, wday, month, year;
#define BLYNK_PRINT Serial 
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <avr/pgmspace.h>
SoftwareSerial EspSerial(3, 2);
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
char auth[] = "z-24CZRYcWeauh3BEjdszQoz1FvsYXfa";
char ssid[] = "Tuong_Vy";
char pass[] = "24112007";
boolean a;
int m,h;
void setup() 
{
 Serial.begin(9600);
 Wire.begin();
 //setTime(20, 15, 00, 6, 13, 12, 19);
 EspSerial.begin(ESP8266_BAUD);
 Blynk.begin(auth, wifi, ssid, pass);  
 pinMode(5, OUTPUT);
}

BLYNK_WRITE(V0)
{
  a = param.asInt();
}
BLYNK_WRITE(V1) 
{
 writedata(0x10, param.asInt());
}
BLYNK_WRITE(V2) 
{
 writedata(0x11, param.asInt());
}

void loop() 
{
 readDS1307();
 h=readdata(0x10);
 m=readdata(0x11);
 Blynk.run();

 if (((hour<=h)&&(minute<=m))||(a==1))
 {
  digitalWrite(5,HIGH);
 }
 else
 {
  digitalWrite(5,LOW);
 }
}
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
 year += 2000;    
}
void writedata(byte ad1, int data)
{
  Wire.beginTransmission(DS1307);
  Wire.write(ad1);
  Wire.write(dec2bcd(data));
  Wire.endTransmission();
}
int readdata(byte ad2)
{
  Wire.beginTransmission(DS1307);
  Wire.write(ad2);
  Wire.endTransmission();
  Wire.requestFrom(0x68,1);
  return(bcd2dec(Wire.read()));
}
