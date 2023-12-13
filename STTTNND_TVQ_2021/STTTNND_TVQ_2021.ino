#include "SPI.h"
#include "MFRC522.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
#define SS_PIN 10
#define RST_PIN 9 
#define coi 4
#define N1 5
#define N2 6
#define N3 3
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
#include <Wire.h>
const byte DS1307 = 0x68;
const byte NumberOfFields = 7;
const byte NumberOfFields2 = 1;
byte second, minute, hour, day, wday, month, year;
byte buoian1, buoian2, buoian3, buoian4;
byte anvat1, anvat2, anvat3, anvat4;
byte boan1, boan2, boan3, boan4;
byte nghihoc1, nghihoc2, nghihoc3, nghihoc4;
byte luuthe111, luuthe222, luuthe333, luuthe444;
boolean gt1, gt2, gt3, gt4;
byte e, d1, d2, d3, dem;  
int luuthe11, luuthe22, luuthe33, luuthe44;   
int t1, t2, t3, t4, t5, t6, t7, t8;

void setup() 
{
 Serial.begin(9600);
 SIM900.begin(9600);
 SPI.begin();
 rfid.PCD_Init();
 Wire.begin();
 delay(1000);
 SIM900.println("AT+CMGF=1r");
 delay(1000);
 SIM900.println("AT+CNMI=2,2,0,0,0r");
 delay(1000);
 Serial.println("San sang!!!");
 pinMode(coi, OUTPUT);
 digitalWrite(coi, 0);
 pinMode(N1, INPUT_PULLUP);
 pinMode(N2, INPUT_PULLUP);
 pinMode(N3, INPUT_PULLUP);
 lcd.begin();                  
 lcd.backlight();
 //setTime(20, 33, 00, 4, 21, 07, 21);
 d1=0;
 d2=0;
 d3=0;
 dem=0;
 e=0;
 gt1=1;
 gt2=1;
 gt3=1;
 gt4=1;
 boan1=1;
 boan2=1;
 boan3=1;
 boan4=1;
 t1 = readdata(0x10);
 t2 = readdata(0x11);
 t3 = readdata(0x12);
 t4 = readdata(0x13);
 t5 = readdata(0x14);
 t6 = readdata(0x15);
 t7 = readdata(0x16);
 t8 = readdata(0x17);
 buoian1=(t1-(t1%10))/10;
 buoian2=(t2-(t2%10))/10;
 buoian3=(t3-(t3%10))/10;
 buoian4=(t4-(t4%10))/10;
 nghihoc1=t5%10;
 nghihoc2=t6%10;
 nghihoc3=t7%10;
 nghihoc4=t8%10;
 anvat1=t1%10;
 anvat2=t2%10;
 anvat3=t3%10;
 anvat4=t4%10;
 lcd.setCursor(1,1);
 lcd.print("TBI DANG KHOI DONG");
 lcd.setCursor(15,2);
 lcd.print(".");
 delay(1000);
 lcd.setCursor(16,2);
 lcd.print(".");
 delay(1000);
 lcd.setCursor(17,2);
 lcd.print(".");
 delay(1000);
 lcd.setCursor(18,2);
 lcd.print(".");
 delay(1000);
 lcd.setCursor(19,2);
 lcd.print(".");
 delay(1000);
 lcd.clear();
}
void loop() 
{
 readDS1307();
 hienthilcd();
 //ĐOẠN CHƯƠNG TRÌNH BÁO PHỤ HUYNH KHI HỌC SINH BỎ ĂN------------------------------------------------------
 if ((hour=12&&minute==00&&second==0)&&(boan1>=1))
 {
  boan1--;
  SendMessage3();
 }
 if ((hour=12&&minute==00&&second==15)&&(boan2>=1))
 {
  boan2--;
  SendMessage3();
 }
 if ((hour=12&&minute==30&&second==00))
 {
  gt1=1;
  gt2=1;
  gt3=1;
  gt4=1;
 }
 if ((hour=18&&minute==30&&second==00))
 {
  gt3=1;
  gt4=1;
 }
 //ĐOẠN CHƯƠNG TRÌNH CHỌN CHẾ ĐỘ---------------------------------------------------------------------------
 if (digitalRead(N1)==0)
 {
  d1=1;
 }
 if (digitalRead(N2)==0)
 {
  d2=1;
 }
 if (digitalRead(N3)==0)
 {
  while (digitalRead(N3)==0) {}
  d3++;
 }
 //ĐOẠN CHƯƠNG TRÌNH NHẬN TIN NHẮN XIN PHÉP NGHI HỌC-------------------------------------------------------
 while (SIM900.available() > 0) 
 {
  char e = SIM900.read();
  if (e == '!')
  {
   nghihoc1++;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(50);
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   luuthe111 = boan1*10+nghihoc1;
   writedata(0x14, luuthe111);
   t5 =readdata(0x14);
  }
  if (e == '@')
  {
   nghihoc2++;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(50);
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   luuthe222 = boan2*10+nghihoc2;
   writedata(0x15, luuthe222);
   t6 =readdata(0x15);
  }
  if (e == '#')
  {
   nghihoc3++;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(50);
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   luuthe333 = boan3*10+nghihoc3;
   writedata(0x16, luuthe333);
   t7 =readdata(0x16);
  }
  if (e == '*')
  {
   nghihoc4++;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(50);
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   luuthe444 = boan4*10+nghihoc4;
   writedata(0x17, luuthe444);
   t8 =readdata(0x17);
  }
 } 
 //ĐOẠN CHƯƠNG TRÌNH ĐỌC THẺ TỪ----------------------------------------------------------------------------
 if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
  return;
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) 
      {
       Serial.println(F("The cua ban khong phu hop"));
       return;
      }
  String strID = "";
  for (byte i = 0; i < 4; i++) 
  {
   strID+=(rfid.uid.uidByte[i] < 0x10 ? "0" : "")+
          String(rfid.uid.uidByte[i], HEX)+
          (i != 3 ? ":" : "");
  }
  strID.toUpperCase();
  Serial.print("Ma pin the: ");
  Serial.println(strID);
  delay(500);
  readDS1307();
  //ĐOẠN CHƯƠNG TRÌNH ĐỌC THẺ 1----------------------------------------------------------------------------
  if ((strID.indexOf("E9:BD:5F:B3") >= 0)&&(d1==1))
  {
   readDS1307();
   if ((gt1==1)&&(hour==11))
   {
    lcd.clear();
    readDS1307();
    hienthilcd();
    d1=0;   
    digitalWrite(coi, 1);
    delay(50);
    digitalWrite(coi, 0);
    delay(50);
    buoian1--;
    boan1--;
    dem++;
    gt1=0;
    lcd.setCursor(0,1);
    lcd.print("M:S05/12A1/K18");
    lcd.setCursor(16,1);
    lcd.print("V:");
    lcd.setCursor(18,1);
    lcd.print(nghihoc1);
    lcd.setCursor(0,2);
    lcd.print("S BUOI AN CON LAI:");
    lcd.setCursor(18,2);
    lcd.print(buoian1);
    lcd.setCursor(0,3);
    lcd.print("S LUOT MUA (KHAC):");
    lcd.setCursor(18,3);
    lcd.print(anvat1);
    delay(4000);
    luuthe11 = buoian1*10+anvat1;
    luuthe111 = nghihoc1;
    writedata(0x10, luuthe11);
    writedata(0x14, luuthe111);
    t1 =readdata(0x10);
    t5 =readdata(0x14);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
   if ((hour!=11)&&(gt1==1))
   {
    d1=0;
    lcd.clear();
    lcd.setCursor(2,2);
    lcd.print("CHUA DEN GIO COM!");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
  }
  if ((strID.indexOf("E9:BD:5F:B3") >= 0)&&(d2==1))
  {
   lcd.clear();
   readDS1307();
   hienthilcd();
   d2=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(100);
   anvat1++;
   lcd.setCursor(0,1);
   lcd.print("M:S05/12A1/K18");
   lcd.setCursor(16,1);
   lcd.print("V:");
   lcd.setCursor(18,1);
   lcd.print(nghihoc1);
   lcd.setCursor(0,2);
   lcd.print("S BUOI AN CON LAI:");
   lcd.setCursor(18,2);
   lcd.print(buoian1);
   lcd.setCursor(0,3);
   lcd.print("S LUOT MUA (KHAC):");
   lcd.setCursor(18,3);
   lcd.print(anvat1);
   delay(4000);
   luuthe11 = buoian1*10+anvat1;
   writedata(0x10, luuthe11);
   t1 =readdata(0x10);
   lcd.clear();
   lcd.setCursor(0,2);
   lcd.print("XMOI NGUOI TIEP THEO");
  }
  if ((strID.indexOf("E9:BD:5F:B3") >= 0)&&(d3==1))
  {
   readDS1307();
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage1();
  }
  if ((strID.indexOf("E9:BD:5F:B3") >= 0)&&(d3==2))
  {
   readDS1307();
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage2();
  }
  //ĐOẠN CHƯƠNG TRÌNH ĐỌC THẺ 2----------------------------------------------------------------------------
  if ((strID.indexOf("B6:C1:1E:1F") >= 0)&&(d1==1))
  {
   readDS1307();
   if ((hour==11)&&(gt2==1))
   {
    lcd.clear();
    readDS1307();
    hienthilcd();
    d1=0;   
    digitalWrite(coi, 1);
    delay(50);
    digitalWrite(coi, 0);
    delay(50);
    buoian2--;
    boan2--;
    dem++;
    gt2=0;
    lcd.setCursor(0,1);
    lcd.print("M:S30/12A1/K18");
    lcd.setCursor(16,1);
    lcd.print("V:");
    lcd.setCursor(18,1);
    lcd.print(nghihoc2);
    lcd.setCursor(0,2);
    lcd.print("S BUOI AN CON LAI:");
    lcd.setCursor(18,2);
    lcd.print(buoian2);
    lcd.setCursor(0,3);
    lcd.print("S LUOT MUA (KHAC):");
    lcd.setCursor(18,3);
    lcd.print(anvat2);
    delay(4000);
    luuthe22 = buoian2*10+anvat2;
    luuthe222 = nghihoc2;
    writedata(0x11, luuthe22);
    writedata(0x15, luuthe222);
    t2 =readdata(0x11);
    t6 =readdata(0x15);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
   if ((hour!=11)&&(gt2==1))
   {
    d1=0;
    lcd.clear();
    lcd.setCursor(2,2);
    lcd.print("CHUA DEN GIO COM!");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
  }
  if ((strID.indexOf("B6:C1:1E:1F") >= 0)&&(d2==1))
  {
   lcd.clear();
   readDS1307();
   hienthilcd();
   d2=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(100);
   anvat2++;
   lcd.setCursor(0,1);
   lcd.print("M:S30/12A1/K18");
   lcd.setCursor(16,1);
   lcd.print("V:");
   lcd.setCursor(18,1);
   lcd.print(nghihoc2);
   lcd.setCursor(0,2);
   lcd.print("S BUOI AN CON LAI:");
   lcd.setCursor(18,2);
   lcd.print(buoian2);
   lcd.setCursor(0,3);
   lcd.print("S LUOT MUA (KHAC):");
   lcd.setCursor(18,3);
   lcd.print(anvat2);
   delay(4000);
   luuthe22 = buoian2*10+anvat2;
   writedata(0x11, luuthe22);
   t2 =readdata(0x11);
   lcd.clear();
   lcd.setCursor(0,2);
   lcd.print("XMOI NGUOI TIEP THEO");
  }
  if ((strID.indexOf("B6:C1:1E:1F") >= 0)&&(d3==1))
  {
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage1();
  }
  if ((strID.indexOf("B6:C1:1E:1F") >= 0)&&(d3==2))
  {
   readDS1307();
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage2();
  }
  //ĐOẠN CHƯƠNG TRÌNH ĐỌC THẺ 3----------------------------------------------------------------------------
  if ((strID.indexOf("69:43:56:B3") >= 0)&&(d1==1))
  {
   readDS1307();
   if ((hour==11)&&(gt3==1))
   {
    lcd.clear();
    readDS1307();
    hienthilcd();
    d1=0;   
    digitalWrite(coi, 1);
    delay(50);
    digitalWrite(coi, 0);
    delay(50);
    buoian3--;
    boan3--;
    dem++;
    gt3=0;
    lcd.setCursor(0,1);
    lcd.print("M:S31/12A1/K18");
    lcd.setCursor(16,1);
    lcd.print("V:");
    lcd.setCursor(18,1);
    lcd.print(nghihoc3);
    lcd.setCursor(0,2);
    lcd.print("S BUOI AN CON LAI:");
    lcd.setCursor(18,2);
    lcd.print(buoian3);
    lcd.setCursor(0,3);
    lcd.print("S LUOT MUA (KHAC):");
    lcd.setCursor(18,3);
    lcd.print(anvat3);
    delay(4000);
    luuthe33 = buoian3*10+anvat3;
    luuthe333 = nghihoc3;
    writedata(0x12, luuthe33);
    writedata(0x16, luuthe333);
    t3 =readdata(0x12);
    t7 =readdata(0x16);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
   if ((hour!=11)&&(gt3==1))
   {
    d1=0;
    lcd.clear();
    lcd.setCursor(2,2);
    lcd.print("CHUA DEN GIO COM!");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
  }
  if ((strID.indexOf("69:43:56:B3") >= 0)&&(d2==1))
  {
   lcd.clear();
   readDS1307();
   hienthilcd();
   d2=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(100);
   anvat3++;
   lcd.setCursor(0,1);
   lcd.print("M:S31/12A1/K18");
   lcd.setCursor(16,1);
   lcd.print("V:");
   lcd.setCursor(18,1);
   lcd.print(nghihoc3);
   lcd.setCursor(0,2);
   lcd.print("S BUOI AN CON LAI:");
   lcd.setCursor(18,2);
   lcd.print(buoian3);
   lcd.setCursor(0,3);
   lcd.print("S LUOT MUA (KHAC):");
   lcd.setCursor(18,3);
   lcd.print(anvat3);
   delay(4000);
   luuthe33 = buoian3*10+anvat3;
   writedata(0x12, luuthe33);
   t3 =readdata(0x12);
   lcd.clear();
   lcd.setCursor(0,2);
   lcd.print("XMOI NGUOI TIEP THEO");
  }
  if ((strID.indexOf("69:43:56:B3") >= 0)&&(d3==1))
  {
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage1();
  }
  if ((strID.indexOf("69:43:56:B3") >= 0)&&(d3==2))
  {
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage2();
  }
  //ĐOẠN CHƯƠNG TRÌNH ĐỌC THẺ 4----------------------------------------------------------------------------
  if ((strID.indexOf("B9:05:F8:C1") >= 0)&&(d1==1))
  {
   readDS1307();
   if ((hour==11)&&(gt4==1))
   {
    lcd.clear();
    readDS1307();
    hienthilcd();
    d1=0;   
    digitalWrite(coi, 1);
    delay(50);
    digitalWrite(coi, 0);
    delay(50);
    buoian4--;
    boan4--;
    dem++;
    gt4=0;
    lcd.setCursor(0,1);
    lcd.print("M:S11/12A1/K18");
    lcd.setCursor(16,1);
    lcd.print("V:");
    lcd.setCursor(18,1);
    lcd.print(nghihoc4);
    lcd.setCursor(0,2);
    lcd.print("S BUOI AN CON LAI:");
    lcd.setCursor(18,2);
    lcd.print(buoian4);
    lcd.setCursor(0,3);
    lcd.print("S LUOT MUA (KHAC):");
    lcd.setCursor(18,3);
    lcd.print(anvat4);
    delay(4000);
    luuthe44 = buoian4*10+anvat4;
    luuthe444 = nghihoc4;
    writedata(0x13, luuthe44);
    writedata(0x17, luuthe444);
    t4 =readdata(0x13);
    t8 =readdata(0x17);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
   if ((hour!=11)&&(gt4==1))
   {
    d1=0;
    lcd.clear();
    lcd.setCursor(2,2);
    lcd.print("CHUA DEN GIO COM!");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("XMOI NGUOI TIEP THEO");
   }
  }
  if ((strID.indexOf("B9:05:F8:C1") >= 0)&&(d2==1))
  {
   lcd.clear();
   readDS1307();
   hienthilcd();
   d2=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(100);
   anvat4++;
   lcd.setCursor(0,1);
   lcd.print("M:S11/12A1/K18");
   lcd.setCursor(16,1);
   lcd.print("V:");
   lcd.setCursor(18,1);
   lcd.print(nghihoc4);
   lcd.setCursor(0,2);
   lcd.print("S BUOI AN CON LAI:");
   lcd.setCursor(18,2);
   lcd.print(buoian4);
   lcd.setCursor(0,3);
   lcd.print("S LUOT MUA (KHAC):");
   lcd.setCursor(18,3);
   lcd.print(anvat4);
   delay(4000);
   luuthe44 = buoian4*10+anvat4;
   writedata(0x13, luuthe44);
   t4 =readdata(0x13);
   lcd.clear();
   lcd.setCursor(0,2);
   lcd.print("XMOI NGUOI TIEP THEO");
  }
  if ((strID.indexOf("B9:05:F8:C1") >= 0)&&(d3==1))
  {
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage1();
  }
  if ((strID.indexOf("B9:05:F8:C1") >= 0)&&(d3==2))
  {
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage2();
  }
  //ĐOẠN CHƯƠNG TRÌNH CỦA QUẢN LÝ--------------------------------------------------------------------------
  if ((strID.indexOf("79:71:5C:B3") >= 0)&&(d1==1))
  {
   lcd.clear();
   readDS1307();
   hienthilcd();
   d1=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   delay(100);
   lcd.setCursor(1,1);
   lcd.print("DANH SACH NGHI HOC");
   //
   if (nghihoc1>0)
   {
    lcd.setCursor(1,2);
    lcd.print("S05/12A1");
   }
   //
   if ((nghihoc2>0)&&(nghihoc1>0))
   {
    lcd.setCursor(11,2);
    lcd.print("S30/12A1");
   }
   if ((nghihoc2>0)&&(nghihoc1==0))
   {
    lcd.setCursor(1,2);
    lcd.print("S30/12A1");
   }
   //
   if ((nghihoc3>0)&&(nghihoc2>0)&&(nghihoc1>0))
   {
    lcd.setCursor(1,3);
    lcd.print("S31/12A1");
   }
   if ((nghihoc3>0)&&(nghihoc2>0)&&(nghihoc1==0))
   {
    lcd.setCursor(11,2);
    lcd.print("S31/12A1");
   }
   if ((nghihoc3>0)&&(nghihoc2==0)&&(nghihoc1==0))
   {
    lcd.setCursor(1,2);
    lcd.print("S31/12A1");
   }
   //
   if ((nghihoc4>0)&&(nghihoc3>0)&&(nghihoc2>0)&&(nghihoc1>0))
   {
    lcd.setCursor(11,3);
    lcd.print("S11/12A1");
   }
   if ((nghihoc4>0)&&(nghihoc3>0)&&(nghihoc2>0)&&(nghihoc1==0))
   {
    lcd.setCursor(1,3);
    lcd.print("S11/12A1");
   }
   if ((nghihoc4>0)&&(nghihoc3>0)&&(nghihoc2==0)&&(nghihoc1==0))
   {
    lcd.setCursor(11,2);
    lcd.print("S11/12A1");
   }
   if ((nghihoc4>0)&&(nghihoc3==0)&&(nghihoc2==0)&&(nghihoc1==0))
   {
    lcd.setCursor(1,2);
    lcd.print("S11/12A1");
   }
   delay(5000);
   lcd.clear();
   lcd.setCursor(0,2);
   lcd.print("XMOI NGUOI TIEP THEO");
  }
  if ((strID.indexOf("79:71:5C:B3") >= 0)&&(d2==1))
  {
   lcd.clear();
   readDS1307();
   hienthilcd();
   d2=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   lcd.setCursor(6,1);
   lcd.print("THONG KE");
   lcd.setCursor(0,2);
   lcd.print("PHAN AN:");
   lcd.setCursor(8,2);
   lcd.print(dem);
   lcd.setCursor(0,3);
   lcd.print("KHAC:");
   lcd.setCursor(5,3);
   lcd.print(anvat1+anvat2+anvat3+anvat4);
   lcd.setCursor(7,3);
   lcd.print("=>");
   lcd.setCursor(9,3);
   lcd.print((anvat1+anvat2+anvat3+anvat4)*10);
   lcd.setCursor(12,3);
   lcd.print("000VND");
   delay(4000);
   lcd.clear();
   lcd.setCursor(0,2);
   lcd.print("XMOI NGUOI TIEP THEO");
  }
  if ((strID.indexOf("79:71:5C:B3") >= 0)&&(d3==1))
  {
   d3=0;
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   SendMessage1();
  }
  if ((strID.indexOf("79:71:5C:B3") >= 0)&&(d3==2))
  {
   digitalWrite(coi, 1);
   delay(50);
   digitalWrite(coi, 0);
   d3=0;
   buoian1=5;
   buoian2=5;
   buoian3=9;
   buoian4=9;
   nghihoc1=0;
   nghihoc2=0;
   nghihoc3=0;
   nghihoc4=0;
   anvat1=0;
   anvat2=0;
   anvat3=0;
   anvat4=0;
   luuthe11 = buoian1*10+anvat1;
   luuthe22 = buoian2*10+anvat2;
   luuthe33 = buoian3*10+anvat3;
   luuthe44 = buoian4*10+anvat4;
   luuthe111 = boan1*10+nghihoc1;
   luuthe222 = boan2*10+nghihoc2;
   luuthe333 = boan3*10+nghihoc3;
   luuthe444 = boan4*10+nghihoc4;
   writedata(0x10, luuthe11);
   writedata(0x11, luuthe22);
   writedata(0x12, luuthe33);
   writedata(0x13, luuthe44);
   writedata(0x14, luuthe111);
   writedata(0x15, luuthe222);
   writedata(0x16, luuthe333);
   writedata(0x17, luuthe444);
   t1 =readdata(0x10);
   t2 =readdata(0x11);
   t3 =readdata(0x12);
   t4 =readdata(0x13);
   t5 =readdata(0x14);
   t6 =readdata(0x15);
   t7 =readdata(0x16);
   t8 =readdata(0x17);
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

void hienthilcd()
{
 //ĐOẠN CT IN THGIAN RA LCD
 lcd.setCursor(0,0);
 lcd.print("D:");
 if (day>=10)
 {
 lcd.setCursor(2,0);
 lcd.print(day);
 }
 else
 {
  lcd.setCursor(2,0);
  lcd.print(0);
  lcd.setCursor(3,0);
  lcd.print(day);
 }
 lcd.setCursor(4,0);
 lcd.print("/");
 if (month>=10)
 {
 lcd.setCursor(5,0);
 lcd.print(month);
 }
 else
 {
  lcd.setCursor(5,0);
  lcd.print(0);
  lcd.setCursor(6,0);
  lcd.print(month);
 }
 lcd.setCursor(7,0);
 lcd.print("/");
 lcd.setCursor(8,0);
 lcd.print(2000+year);
 lcd.setCursor(13,0);
 lcd.print("H:");
 if (hour>=10)
 {
  lcd.setCursor(15,0);
  lcd.print(hour);
 }
 else
 {
  lcd.setCursor(15,0);
  lcd.print(0);
  lcd.setCursor(16,0);
  lcd.print(hour);
 }
 lcd.setCursor(17,0);
 lcd.print(":");
 if (month<65)
 {
  if (minute>=10)
  {
   lcd.setCursor(18,0);
   lcd.print(minute);
  }
  else
  {
   lcd.setCursor(18,0);
   lcd.print(0);
   lcd.setCursor(19,0);
   lcd.print(minute);
  } 
 }
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

void SendMessage1()
{
  SIM900.println("AT+CMGF=1");
  delay(1000);
  SIM900.println("AT+CMGS=\"+84799896871\"\r");
  delay(1000);
  SIM900.println("THONG BAO DEN PHU HUYNH: LEN TRUONG DON HOC SINH VE");
  delay(100);
  SIM900.println((char)26);
  delay(1000);
}

void SendMessage2()
{
  SIM900.println("AT+CMGF=1");
  delay(1000);
  SIM900.println("AT+CMGS=\"+84799896871\"\r");
  delay(1000);
  SIM900.println("THONG BAO DEN PHU HUYNH: MANG BO SUNG TAI LIEU CHO HOC SINH");
  delay(100);
  SIM900.println((char)26);
  delay(1000);
}

void SendMessage3()
{
  SIM900.println("AT+CMGF=1");
  delay(1000);
  SIM900.println("AT+CMGS=\"+84799896871\"\r");
  delay(1000);
  SIM900.println("THONG BAO DEN PHU HUYNH: HOC SINH BO AN");
  delay(100);
  SIM900.println((char)26);
  delay(1000);
}
