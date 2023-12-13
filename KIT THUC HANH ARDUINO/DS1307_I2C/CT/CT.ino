#include <Wire.h>
#include <LiquidCrystal_I2C_AvrI2C.h>
#define encoderPinA 2
#define encoderPinB 3
#define Button 4
int encoderPos,chon,lastReportedPos;
boolean rotating,B_set,A_set;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);

//----------------------------------------------------
/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
const byte NumberOfFields2 = 1;
int second, minute, hour, day, wday, month, year;
void setup(){
  pinMode(encoderPinA, INPUT_PULLUP); // new method of enabling pullups
  pinMode(encoderPinB, INPUT_PULLUP); 
  pinMode(Button, INPUT_PULLUP);
   // encoder pin on interrupt 0 (pin 2)
  attachInterrupt(0, doEncoderA, CHANGE);
// encoder pin on interrupt 1 (pin 3)
  attachInterrupt(1, doEncoderB, CHANGE);
  
  lcd.begin();
  lcd.backlight();
  lcd.print("Bui Minh Thao");
  delay(3000);
  lcd.clear();
  //setTime(15, 16, 00, 7, 16, 2, 19); // 12:30:45 CN 08-02-2015
 
}

//----------------------------------------------------
void loop(){
  readDS1307();
  displaytime();
  caidat();
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

void displaytime()
{
 conveter(0,0,hour);
 lcd.setCursor(2,0);
 lcd.print(":");
 conveter(3,0,minute);
 lcd.setCursor(5,0);
 lcd.print(":");
 conveter(6,0,second);
 lcd.setCursor(10,0);
 lcd.print("THU:");
 if(wday==1)
 {
   lcd.setCursor(14,0);
   lcd.print("CN");
 }
 else
 {
  conveter(14,0,wday);
 }
 conveter(0,1,day);
 lcd.setCursor(2,1);
 lcd.print("/");
 conveter(3,1,month);
 lcd.setCursor(5,1);
 lcd.print("/");
 lcd.setCursor(6,1);
 lcd.print(year);
}
void writedata(byte add1, byte data)
{
  Wire.beginTransmission(DS1307);
  Wire.write(add1);
  Wire.write(dec2bcd(data));
  Wire.endTransmission();
}
byte readdata(byte add2)
{
  Wire.beginTransmission(DS1307);
  Wire.write(add2);
  Wire.endTransmission();
  Wire.requestFrom(DS1307, NumberOfFields2);
  return  bcd2dec(Wire.read());
        
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
        
        second = bcd2dec(Wire.read() & 0x7f);
        minute = bcd2dec(Wire.read() );
        hour   = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
        wday   = bcd2dec(Wire.read() );
        day    = bcd2dec(Wire.read() );
        month  = bcd2dec(Wire.read() );
        year   = bcd2dec(Wire.read() );
        year += 2000;    
}
// Interrupt on A changing state
void doEncoderA(){
  // debounce
  if ( rotating ) delay (1);  // wait a little until the bouncing is done

  // Test transition, did things really change? 
  if( digitalRead(encoderPinA) != A_set ) {  // debounce once more
    A_set = !A_set;

    // adjust counter + if A leads B
    if ( A_set && !B_set ) 
      encoderPos += 1;

    rotating = false;  // no more debouncing until loop() hits again
  }
}

// Interrupt on B changing state, same as A above
void doEncoderB(){
  
  if ( rotating ) delay (1);
  if( digitalRead(encoderPinB) != B_set ) {
    B_set = !B_set;
    
    //  adjust counter - 1 if B leads A
    if( B_set && !A_set ) 
      encoderPos -= 1;
      
    rotating = false;
  }
}
void caidat()
{
  rotating = true;  // reset the debouncer
if(digitalRead(Button)==0){  
  do{}
  while(digitalRead(Button)==0);
  chon++;
  
  switch(chon)
  {
    case 1:    encoderPos=hour; break;
    case 2:    encoderPos=minute; break;
    case 3:    encoderPos=second; break;
    case 4:    encoderPos=wday; break;
    case 5:    encoderPos=day; break;
    case 6:    encoderPos=month; break;
    case 7:    encoderPos=year-2000; break;
  }
  if(chon==8) 
  {
  chon=0;
  lcd.setCursor(14,1);
  lcd.clear();
  }
  else  conveter(14,1,chon);
}
  
  if ((lastReportedPos != encoderPos)&&(chon==1)) {
    if(encoderPos<0) encoderPos=23;
    if(encoderPos==24) encoderPos=0;
    lastReportedPos = encoderPos;
    setTime(encoderPos, minute, second, wday, day, month, year-2000); // 12:30:45 CN 08-02-2015
  }
    if ((lastReportedPos != encoderPos)&&(chon==2)) {
    if(encoderPos<0) encoderPos=59;
    if(encoderPos==60) encoderPos=0;
    lastReportedPos = encoderPos;
    setTime(hour, encoderPos, second, wday, day, month, year-2000); // 12:30:45 CN 08-02-2015
  }
    if ((lastReportedPos != encoderPos)&&(chon==3)) {
    if(encoderPos<0) encoderPos=59;
    if(encoderPos==60) encoderPos=0;
    lastReportedPos = encoderPos;
    setTime(hour, minute, encoderPos, wday, day, month, year-2000); // 12:30:45 CN 08-02-2015
  }
  if ((lastReportedPos != encoderPos)&&(chon==4)) {
    if(encoderPos<1) encoderPos=7;
    if(encoderPos==8) encoderPos=1;
    lastReportedPos = encoderPos;
    setTime(hour, minute, second, encoderPos, day, month, year-2000); // 12:30:45 CN 08-02-2015
  }
  if ((lastReportedPos != encoderPos)&&(chon==5)) {
    if(encoderPos<1) encoderPos=31;
    if(encoderPos==32) encoderPos=1;
    lastReportedPos = encoderPos;
    setTime(hour, minute, second, wday, encoderPos, month, year-2000); // 12:30:45 CN 08-02-2015
  }
  if ((lastReportedPos != encoderPos)&&(chon==6)) {
    if(encoderPos<1) encoderPos=12;
    if(encoderPos==13) encoderPos=1;
    lastReportedPos = encoderPos;
    setTime(hour, minute, second, wday, day, encoderPos, year-2000); // 12:30:45 CN 08-02-2015
  }
   if ((lastReportedPos != encoderPos)&&(chon==7)) {
    if(encoderPos<0) encoderPos=99;
    if(encoderPos==100) encoderPos=0;
    lastReportedPos = encoderPos;
    setTime(hour, minute, second, wday, day, month, encoderPos); // 12:30:45 CN 08-02-2015
  }
}


