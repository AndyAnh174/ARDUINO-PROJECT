#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
char incoming_char=0;
#include <Wire.h>
/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
const byte NumberOfFields2 = 1;
int second, minute, hour, day, wday, month, year;
#define N1 3
#define N2 4
#define N3 5
#define N4 6
void setup() 
{
  Wire.begin();
  SIM900.begin(9600);
  Serial.begin(9600); 
  delay(1000);
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW); 
  pinMode(N1, INPUT_PULLUP);
  pinMode(N2, INPUT_PULLUP);
  pinMode(N3, INPUT_PULLUP);
  pinMode(N4, INPUT_PULLUP);
  //setTime(15, 21, 00, 5, 04, 03, 20);
}

void loop() 
{
 readDS1307();
 Serial.print(hour);
 Serial.print(":");
 Serial.print(minute);
 Serial.print(":");
 Serial.println(second);
 //
 if(SIM900.available() >0) 
 {
  incoming_char=SIM900.read(); 
  Serial.print(incoming_char);
  if (incoming_char == 'A')
  {
   digitalWrite(2, HIGH);
   delay(100);
   digitalWrite(2, LOW);
   Serial.print("DA CHO AN");
  }
  if (incoming_char == 'B')
  {
   digitalWrite(2, HIGH);
   delay(150);
   digitalWrite(2, LOW);
   Serial.print("DA CHO AN");
  }
  if (incoming_char == 'C')
  {
   digitalWrite(2, HIGH);
   delay(200);
   digitalWrite(2, LOW);
   Serial.print("DA CHO AN");
  }
 }
 //
 if (digitalRead(N1)==0)
 {
  while (digitalRead(N1)==0){}
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  Serial.println("DA CHO AN");
 }
 //
 if ((digitalRead(N2)==0))
 {
  while (digitalRead(N2)==0){}
  Serial.println("CHD CHO AN 2LAN/NGAY");
  while (1)
  {
   readDS1307();
   Serial.print(hour);
   Serial.print(":");
   Serial.print(minute);
   Serial.print(":");
   Serial.println(second);
   if ((hour==9&&minute==0&&second==0)||(hour==18&&minute==0&&second==0))
   {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    Serial.println("DA CHO AN");
   }
   if (digitalRead(N2)==0)
   {
    while (digitalRead(N2)==0){}
    Serial.println("THOAT CHD CHO AN 2LAN/NGAY");
    break;
   }
   if (digitalRead(N1)==0)
   {
    while (digitalRead(N1)==0){}
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    Serial.println("DA CHO AN");
   }
   if(SIM900.available() >0) 
   {
    incoming_char=SIM900.read(); 
    Serial.print(incoming_char);
    if (incoming_char == 'A')
    {
     digitalWrite(2, HIGH);
     delay(100);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
    if (incoming_char == 'B')
    {
     digitalWrite(2, HIGH);
     delay(150);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
    if (incoming_char == 'C')
    {
     digitalWrite(2, HIGH);
     delay(200);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
   }
  }
 }
 //
 if ((digitalRead(N3)==0))
 {
  while (digitalRead(N3)==0){}
  Serial.println("CHD CHO AN 3LAN/NGAY");
  while (1)
  {
   readDS1307();
   Serial.print(hour);
   Serial.print(":");
   Serial.print(minute);
   Serial.print(":");
   Serial.println(second);
   if ((hour==8&&minute==0&&second==0)||(hour==12&&minute==0&&second==0)||(hour==17&&minute==0&&second==0))
   {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    Serial.println("DA CHO AN");
   }
   if (digitalRead(N3)==0)
   {
    while (digitalRead(N3)==0){}
    Serial.println("THOAT CHD CHO AN 3LAN/NGAY");
    break;
   }
   if (digitalRead(N1)==0)
   {
    while (digitalRead(N1)==0){}
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    Serial.println("DA CHO AN");
   }
   if(SIM900.available() >0) 
   {
    incoming_char=SIM900.read(); 
    Serial.print(incoming_char);
    if (incoming_char == 'A')
    {
     digitalWrite(2, HIGH);
     delay(100);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
    if (incoming_char == 'B')
    {
     digitalWrite(2, HIGH);
     delay(150);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
    if (incoming_char == 'C')
    {
     digitalWrite(2, HIGH);
     delay(200);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
   }
  }
 }
 //
 if ((digitalRead(N4)==0))
 {
  while (digitalRead(N4)==0){}
  Serial.println("CHD CHO AN 4LAN/NGAY");
  while (1)
  {
   readDS1307();
   Serial.print(hour);
   Serial.print(":");
   Serial.print(minute);
   Serial.print(":");
   Serial.println(second);
   if ((hour==7&&minute==0&&second==0)||(hour==11&&minute==0&&second==0)||(hour==15&&minute==0&&second==0)||(hour==19&&minute==0&&second==0))
   {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    Serial.println("DA CHO AN");
   }
   if (digitalRead(N4)==0)
   {
    while (digitalRead(N4)==0){}
    Serial.println("THOAT CHD CHO AN 4LAN/NGAY");
    break;
   }
   if (digitalRead(N1)==0)
   {
    while (digitalRead(N1)==0){}
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    Serial.println("DA CHO AN");
   }
   if(SIM900.available() >0) 
   {
    incoming_char=SIM900.read(); 
    Serial.print(incoming_char);
    if (incoming_char == 'A')
    {
     digitalWrite(2, HIGH);
     delay(100);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
    if (incoming_char == 'B')
    {
     digitalWrite(2, HIGH);
     delay(150);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
    if (incoming_char == 'C')
    {
     digitalWrite(2, HIGH);
     delay(200);
     digitalWrite(2, LOW);
     Serial.print("DA CHO AN");
    }
   }
  }
 }
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
