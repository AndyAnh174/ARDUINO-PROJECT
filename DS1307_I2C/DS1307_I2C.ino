#include <Wire.h>
/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
const byte NumberOfFields2 = 1;
int second, minute, hour, day, wday, month, year;

void setup()
{
 Serial.begin(9600);
 Wire.begin(); 
 setTime(13, 11, 00, 7, 14, 8, 21); // 12:30:45 CN 08-02-2015
}

void loop()
{
 readDS1307();
 Serial.print(hour);
 Serial.print(":");
 Serial.print(minute);
 Serial.print(":");
 Serial.print(second);
 Serial.println();
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
/* Chuyển từ Decimal sang BCD */
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
 
 second = bcd2dec(Wire.read() & 0x7f); //GIÂY
 minute = bcd2dec(Wire.read() );       //PHÚT  
 hour   = bcd2dec(Wire.read() & 0x3f); //GIỜ
 wday   = bcd2dec(Wire.read() );       //THỨ
 day    = bcd2dec(Wire.read() );       //NGÀY
 month  = bcd2dec(Wire.read() );       //THÁNG
 year   = bcd2dec(Wire.read() );       //NĂM
 year += 2000;    
}
