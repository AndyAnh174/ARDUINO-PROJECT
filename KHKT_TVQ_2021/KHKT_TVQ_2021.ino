#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
SoftwareSerial mySoftwareSerial(11,10);
DFRobotDFPlayerMini myDFPlayer;

#define ANGIANG   41
#define BRVT      A3
#define BACGIANG  4
#define BACKAN    29
#define BACLIEU   49
#define BACNINH   14
#define BENTRE    33
#define BINHDINH  32
#define BINHDUONG A5
#define BINHPHUOC A7
#define BINHTHUAN 40
#define CAMAU     51
#define CANTHO    A11
#define CAOBANG   31
#define DANANG    A10
#define DAKLAK    46
#define DAKNONG   48
#define DIENBIEN  13
#define DONGNAI   A1
#define DONGTHAP  39
#define GIALAI    44
#define HAGIANG   21
#define HANAM     28
#define HANOI     8
#define HATINH    A2
#define HAIDUONG  20
#define HAIPHONG  18
#define HAUGIANG  45
#define HOABINH   17
#define HUNGYEN   16
#define KHANHHOA  36
#define KIENGIANG 43
#define KONTUM    42
#define LAICHAU   19
#define LAMDONG   50
#define LANGSON   2
#define LAOCAI    7
#define LONGAN    A13
#define NAMDINH   24
#define NGHEAN    A0
#define NINHBINH  26
#define NINHTHUAN 38
#define PHUTHO    25
#define PHUYEN    34
#define QUANGBINH A4
#define QUANGNAM  A12
#define QUANGNGAI A14
#define QUANGNINH 6
#define QUANGTRI  A6
#define SOCTRANG  47
#define SONLA     15
#define TAYNINH   A9
#define THAIBINH  22
#define THNGUYEN  27
#define THANHHOA  30
#define HUE       A8
#define TIENGIANG A15
#define TPHCM     52
#define TRAVINH   37
#define TQUANG    23
#define VINHLONG  35
#define VINHPHUC  12
#define YENBAI    9
#define HOANGSA   0
#define TRUONGSA  53
#define chedo     5
#define vungmien  3
int demchedo;
int demvungmien;
int TBB1, TBB2, TBB3, TBB4, TBB5, TBB6;
int DBB1, DBB2, DBB3, DBB4, DBB5, DBB6, DBB7, DBB8, DBB9;
int DBSH1, DBSH2, DBSH3, DBSH4, DBSH5, DBSH6, DBSH7, DBSH8, DBSH9, DBSH10;
int BTB1, BTB2, BTB3, BTB4, BTB5, BTB6;
int DHNTB1, DHNTB2, DHNTB3, DHNTB4, DHNTB5, DHNTB6, DHNTB7, DHNTB8, DHNTB9, DHNTB10;
int TN1, TN2, TN3, TN4, TN5;
int DNB1, DNB2, DNB3, DNB4, DNB5, DNB6;
int DBSCL1, DBSCL2, DBSCL3, DBSCL4, DBSCL5, DBSCL6, DBSCL7, DBSCL8, DBSCL9, DBSCL10, DBSCL11, DBSCL12, DBSCL13;

void setup() {
  Serial.begin(9600);
  pinMode(ANGIANG, INPUT_PULLUP);
  pinMode(BRVT, INPUT_PULLUP);
  pinMode(BACGIANG, INPUT_PULLUP);
  pinMode(BACKAN, INPUT_PULLUP);
  pinMode(BACLIEU, INPUT_PULLUP);
  pinMode(BACNINH, INPUT_PULLUP);
  pinMode(BENTRE, INPUT_PULLUP);
  pinMode(BINHDINH, INPUT_PULLUP);
  pinMode(BINHDUONG, INPUT_PULLUP);
  pinMode(BINHPHUOC, INPUT_PULLUP);
  pinMode(BINHTHUAN, INPUT_PULLUP);
  pinMode(CAMAU, INPUT_PULLUP);
  pinMode(CANTHO, INPUT_PULLUP);
  pinMode(CAOBANG, INPUT_PULLUP);
  pinMode(DANANG, INPUT_PULLUP);
  pinMode(DAKLAK, INPUT_PULLUP);
  pinMode(DAKNONG, INPUT_PULLUP);
  pinMode(DIENBIEN, INPUT_PULLUP);
  pinMode(DONGNAI, INPUT_PULLUP);
  pinMode(DONGTHAP, INPUT_PULLUP);
  pinMode(GIALAI, INPUT_PULLUP);
  pinMode(HAGIANG, INPUT_PULLUP);
  pinMode(HANAM, INPUT_PULLUP);
  pinMode(HANOI, INPUT_PULLUP);
  pinMode(HATINH, INPUT_PULLUP);
  pinMode(HAIDUONG, INPUT_PULLUP);
  pinMode(HAIPHONG, INPUT_PULLUP);
  pinMode(HAUGIANG, INPUT_PULLUP);
  pinMode(HOABINH, INPUT_PULLUP);
  pinMode(HUNGYEN, INPUT_PULLUP);
  pinMode(KHANHHOA, INPUT_PULLUP);
  pinMode(KIENGIANG, INPUT_PULLUP);
  pinMode(KONTUM, INPUT_PULLUP);
  pinMode(LAICHAU, INPUT_PULLUP);
  pinMode(LAMDONG, INPUT_PULLUP);
  pinMode(LANGSON, INPUT_PULLUP);
  pinMode(LAOCAI, INPUT_PULLUP);
  pinMode(LONGAN, INPUT_PULLUP);
  pinMode(NAMDINH, INPUT_PULLUP);
  pinMode(NGHEAN, INPUT_PULLUP);
  pinMode(NINHBINH, INPUT_PULLUP);
  pinMode(NINHTHUAN, INPUT_PULLUP);
  pinMode(PHUTHO, INPUT_PULLUP);
  pinMode(PHUYEN, INPUT_PULLUP);
  pinMode(QUANGBINH, INPUT_PULLUP);
  pinMode(QUANGNAM, INPUT_PULLUP);
  pinMode(QUANGNGAI, INPUT_PULLUP);
  pinMode(QUANGNINH, INPUT_PULLUP);
  pinMode(QUANGTRI, INPUT_PULLUP);
  pinMode(SOCTRANG, INPUT_PULLUP);
  pinMode(SONLA, INPUT_PULLUP);
  pinMode(TAYNINH, INPUT_PULLUP);
  pinMode(THAIBINH, INPUT_PULLUP);
  pinMode(THNGUYEN, INPUT_PULLUP);
  pinMode(THANHHOA, INPUT_PULLUP);
  pinMode(HUE, INPUT_PULLUP);
  pinMode(TIENGIANG, INPUT_PULLUP);
  pinMode(TPHCM, INPUT_PULLUP);
  pinMode(TRAVINH, INPUT_PULLUP);
  pinMode(TQUANG, INPUT_PULLUP);
  pinMode(VINHLONG, INPUT_PULLUP);
  pinMode(VINHPHUC, INPUT_PULLUP);
  pinMode(YENBAI, INPUT_PULLUP);
  pinMode(HOANGSA, INPUT_PULLUP);
  pinMode(TRUONGSA, INPUT_PULLUP);
  pinMode(chedo, INPUT_PULLUP);
  pinMode(vungmien, INPUT_PULLUP);
  TBB1=1;
  TBB2=1;
  TBB3=1;
  TBB4=1;
  TBB5=1;
  TBB6=1;
  DBB1=1;
  DBB2=1;
  DBB3=1;
  DBB4=1;
  DBB5=1;
  DBB6=1;
  DBB7=1;
  DBB8=1;
  DBB9=1;
  DBSH1=1;
  DBSH2=1;
  DBSH3=1;
  DBSH4=1;
  DBSH5=1;
  DBSH6=1;
  DBSH7=1;
  DBSH8=1;
  DBSH9=1;
  DBSH10=1;
  BTB1=1;
  BTB2=1;
  BTB3=1;
  BTB4=1;
  BTB5=1;
  BTB6=1;
  DHNTB1=1;
  DHNTB2=1;
  DHNTB3=1;
  DHNTB4=1;
  DHNTB5=1;
  DHNTB6=1;
  DHNTB7=1;
  DHNTB8=1;
  DHNTB9=1;
  DHNTB10=1;
  TN1=1;
  TN2=1;
  TN3=1;
  TN4=1;
  TN5=1;
  DNB1=1;
  DNB2=1;
  DNB3=1;
  DNB4=1;
  DNB5=1;
  DNB6=1;
  DBSCL1=1;
  DBSCL2=1;
  DBSCL3=1;
  DBSCL4=1;
  DBSCL5=1;
  DBSCL6=1;
  DBSCL7=1;
  DBSCL8=1;
  DBSCL9=1;
  DBSCL10=1;
  DBSCL11=1;
  DBSCL12=1;
  DBSCL13=1;
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  if (!myDFPlayer.begin(mySoftwareSerial)) 
  { 
   Serial.println(F("Unable to begin:"));
   Serial.println(F("1.Please recheck the connection!"));
   Serial.println(F("2.Please insert the SD card!"));
   while(true)
   {
    delay(0); // Code to compatible with ESP8266 watch dog.
   }
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);
  demchedo=0;
}

void loop() 
{
 if (digitalRead(chedo)==0)
 {
  demchedo=1;
  while (digitalRead(chedo)==0){}
 }
 if (demchedo==6) 
 {
  demchedo=1;
 }
 if (demchedo==1)
 {
  myDFPlayer.playFolder(1, 1);
  while (1)
  {
   VITRI();
   if (digitalRead(chedo)==0)
   {
    while (digitalRead(chedo)==0){}
    demchedo+=1;
    break;
   }
  }
 } 
 if (demchedo==2)
 {
  myDFPlayer.playFolder(1, 2);
  while (1)
  {
   DIAHINH();
   if (digitalRead(chedo)==0)
   {
    while (digitalRead(chedo)==0){}
    demchedo+=1;
    break;
   }
  }
 }
 if (demchedo==3)
 {
  myDFPlayer.playFolder(1, 3);
  while (1)
  {
   DANSO();
   if (digitalRead(chedo)==0)
   {
    while (digitalRead(chedo)==0){}
    demchedo+=1;
    break;
   }
  }
 }
 if (demchedo==4)
 {
  myDFPlayer.playFolder(1, 4);
  while (1)
  {
   DKTN(); //vào chương trình con học toán hình
   if (digitalRead(chedo)==0)
   {
    while (digitalRead(chedo)==0){}
    demchedo+=1;
    break;
   }
  }
 }
 if (demchedo==5)
 {
  myDFPlayer.playFolder(1, 5);
  while (1)
  {
   KINHTE(); //vào chương trình con nghe nhạc
   if (digitalRead(chedo)==0)
   {
    while (digitalRead(chedo)==0){}
    demchedo+=1;
    break;
   }
  }
 }
 //
 if (digitalRead(vungmien)==0)
 {
  demvungmien=1;
  while (digitalRead(vungmien)==0){}
 }
 if (demchedo==9) 
 {
  demvungmien=1;
 }
 if (demvungmien==1)
 {
  myDFPlayer.playFolder(7, 1);
  while (1)
  {
   TAYBACBO();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 } 
 if (demvungmien==2)
 {
  myDFPlayer.playFolder(7, 2);
  while (1)
  {
   DONGBACBO();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
 if (demvungmien==3)
 {
  myDFPlayer.playFolder(7, 3);
  while (1)
  {
   DBSONGHONG();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
  if (demvungmien==4)
 {
  myDFPlayer.playFolder(7, 4);
  while (1)
  {
   BACTRUNGBO();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
  if (demvungmien==5)
 {
  myDFPlayer.playFolder(7, 5);
  while (1)
  {
   DHNAMTRUNGBO();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
  if (demvungmien==6)
 {
  myDFPlayer.playFolder(7, 6);
  while (1)
  {
   TAYNGUYEN();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
  if (demvungmien==7)
 {
  myDFPlayer.playFolder(7, 7);
  while (1)
  {
   DONGNAMBO();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
  if (demvungmien==8)
 {
  myDFPlayer.playFolder(7, 8);
  while (1)
  {
   DBSONGCUULONG();
   if (digitalRead(vungmien)==0)
   {
    while (digitalRead(vungmien)==0){}
    demvungmien+=1;
    break;
   }
  }
 }
}

void VITRI()
{
 if (digitalRead(ANGIANG)==0)
 {
  myDFPlayer.playFolder(2, 1);
 }
 else
 if (digitalRead(BRVT)==0)
 {
  myDFPlayer.playFolder(2, 2);
 }
 else
 if (digitalRead(BACGIANG)==0)
 {
  myDFPlayer.playFolder(2, 3);
 }
 else
 if (digitalRead(BACKAN)==0)
 {
  myDFPlayer.playFolder(2, 4);
 }
 else
 if (digitalRead(BACLIEU)==0)
 {
  myDFPlayer.playFolder(2, 5);
 }
 else
 if (digitalRead(BACNINH)==0)
 {
  myDFPlayer.playFolder(2, 6);
 }
 else
 if (digitalRead(BENTRE)==0)
 {
  myDFPlayer.playFolder(2, 7);
 }
 else
 if (digitalRead(BINHDINH)==0)
 {
  myDFPlayer.playFolder(2, 8);
 }
 else
 if (digitalRead(BINHDUONG)==0)
 {
  myDFPlayer.playFolder(2, 9);
 }
 else
 if (digitalRead(BINHPHUOC)==0)
 {
  myDFPlayer.playFolder(2, 10);
 }
 else
 if (digitalRead(BINHTHUAN)==0)
 {
  myDFPlayer.playFolder(2, 11);
 }
 else
 if (digitalRead(CAMAU)==0)
 {
  myDFPlayer.playFolder(2, 12);
 }
 else
 if (digitalRead(CANTHO)==0)
 {
  myDFPlayer.playFolder(2, 13);
 }
 else
 if (digitalRead(CAOBANG)==0)
 {
  myDFPlayer.playFolder(2, 14);
 }
 else
 if (digitalRead(DANANG)==0)
 {
  myDFPlayer.playFolder(2, 15);
 }
 else
 if (digitalRead(DAKLAK)==0)
 {
  myDFPlayer.playFolder(2, 16);
 }
 else
 if (digitalRead(DAKNONG)==0)
 {
  myDFPlayer.playFolder(2, 17);
 }
 else
 if (digitalRead(DIENBIEN)==0)
 {
  myDFPlayer.playFolder(2, 18);
 }
 else
 if (digitalRead(DONGNAI)==0)
 {
  myDFPlayer.playFolder(2, 19);
 }
 else
 if (digitalRead(DONGTHAP)==0)
 {
  myDFPlayer.playFolder(2, 20);
 }
 else
 if (digitalRead(GIALAI)==0)
 {
  myDFPlayer.playFolder(2, 21);
 }
 else
 if (digitalRead(HAGIANG)==0)
 {
  myDFPlayer.playFolder(2, 22);
 }
 else
 if (digitalRead(HANAM)==0)
 {
  myDFPlayer.playFolder(2, 23);
 }
 else
 if (digitalRead(HANOI)==0)
 {
  myDFPlayer.playFolder(2, 24);
 }
 else
 if (digitalRead(HATINH)==0)
 {
  myDFPlayer.playFolder(2, 25);
 }
 else
 if (digitalRead(HAIDUONG)==0)
 {
  myDFPlayer.playFolder(2, 26);
 }
 else
 if (digitalRead(HAIPHONG)==0)
 {
  myDFPlayer.playFolder(2, 27);
 }
 else
 if (digitalRead(HAUGIANG)==0)
 {
  myDFPlayer.playFolder(2, 28);
 }
 else
 if (digitalRead(HOABINH)==0)
 {
  myDFPlayer.playFolder(2, 29);
 }
 else
 if (digitalRead(HUNGYEN)==0)
 {
  myDFPlayer.playFolder(2, 30);
 }
 else
 if (digitalRead(KHANHHOA)==0)
 {
  myDFPlayer.playFolder(2, 31);
 }
 else
 if (digitalRead(KIENGIANG)==0)
 {
  myDFPlayer.playFolder(2, 32);
 }
 else
 if (digitalRead(KONTUM)==0)
 {
  myDFPlayer.playFolder(2, 33);
 }
 else
 if (digitalRead(LAICHAU)==0)
 {
  myDFPlayer.playFolder(2, 34);
 }
 else
 if (digitalRead(LAMDONG)==0)
 {
 myDFPlayer.playFolder(2, 35);
 }
 else
 if (digitalRead(LANGSON)==0)
 {
  myDFPlayer.playFolder(2, 36);
 }
 else
 if (digitalRead(LAOCAI)==0)
 {
  myDFPlayer.playFolder(2, 37);
 }
 else
 if (digitalRead(LONGAN)==0)
 {
  myDFPlayer.playFolder(2, 38);
 }
 else
 if (digitalRead(NAMDINH)==0)
 {
  myDFPlayer.playFolder(2, 39);
 }
 else
 if (digitalRead(NGHEAN)==0)
 {
  myDFPlayer.playFolder(2, 40);
 }
 else
 if (digitalRead(NINHBINH)==0)
 {
  myDFPlayer.playFolder(2, 41);
 }
 else
 if (digitalRead(NINHTHUAN)==0)
 {
  myDFPlayer.playFolder(2, 42);
 }
 else
 if (digitalRead(PHUTHO)==0)
 {
  myDFPlayer.playFolder(2, 43);
 }
 else
 if (digitalRead(PHUYEN)==0)
 {
  myDFPlayer.playFolder(2, 44);
 }
 else
 if (digitalRead(QUANGBINH)==0)
 {
  myDFPlayer.playFolder(2, 45);
 }
 else
 if (digitalRead(QUANGNAM)==0)
 {
  myDFPlayer.playFolder(2, 46);
 }
 else
 if (digitalRead(QUANGNGAI)==0)
 {
  myDFPlayer.playFolder(2, 47);
 }
 else
 if (digitalRead(QUANGNINH)==0)
 {
  myDFPlayer.playFolder(2, 48);
 }
 else
 if (digitalRead(QUANGTRI)==0)
 {
  myDFPlayer.playFolder(2, 49);
 }
 else
 if (digitalRead(SOCTRANG)==0)
 {
  myDFPlayer.playFolder(2, 50);
 }
 else
 if (digitalRead(SONLA)==0)
 {
  myDFPlayer.playFolder(2, 51);
 }
 else
 if (digitalRead(TAYNINH)==0)
 {
  myDFPlayer.playFolder(2, 52);
 }
 else
 if (digitalRead(THAIBINH)==0)
 {
  myDFPlayer.playFolder(2, 53);
 }
 else
 if (digitalRead(THNGUYEN)==0)
 {
  myDFPlayer.playFolder(2, 54);
 }
 else
 if (digitalRead(THANHHOA)==0)
 {
  myDFPlayer.playFolder(2, 55);
 }
 else
 if (digitalRead(HUE)==0)
 {
  myDFPlayer.playFolder(2, 56);
 }
 if (digitalRead(TIENGIANG)==0)
 {
  myDFPlayer.playFolder(2, 57);
 }
 else
 if (digitalRead(TPHCM)==0)
 {
  myDFPlayer.playFolder(2, 58);
 }
 else
 if (digitalRead(TRAVINH)==0)
 {
  myDFPlayer.playFolder(2, 59);
 }
 else
 if (digitalRead(TQUANG)==0)
 {
  myDFPlayer.playFolder(2, 60);
 }
 else
 if (digitalRead(VINHLONG)==0)
 {
  myDFPlayer.playFolder(2, 61);
 }
 else
 if (digitalRead(VINHPHUC)==0)
 {
  myDFPlayer.playFolder(2, 62);
 }
 else
 if (digitalRead(YENBAI)==0)
 {
  myDFPlayer.playFolder(2, 63);
 }
 else
 if (digitalRead(HOANGSA)==0)
 {
  myDFPlayer.playFolder(2, 64);
 }
 else
 if (digitalRead(TRUONGSA)==0)
 {
  myDFPlayer.playFolder(2, 65);
 }
}

void DANSO()
{
 if (digitalRead(ANGIANG)==0)
 {
  myDFPlayer.playFolder(3, 1);
 }
 else
 if (digitalRead(BRVT)==0)
 {
  myDFPlayer.playFolder(3, 2);
 }
 else
 if (digitalRead(BACGIANG)==0)
 {
  myDFPlayer.playFolder(3, 3);
 }
 else
 if (digitalRead(BACKAN)==0)
 {
  myDFPlayer.playFolder(3, 4);
 }
 else
 if (digitalRead(BACLIEU)==0)
 {
  myDFPlayer.playFolder(3, 5);
 }
 else
 if (digitalRead(BACNINH)==0)
 {
  myDFPlayer.playFolder(3, 6);
 }
 else
 if (digitalRead(BENTRE)==0)
 {
  myDFPlayer.playFolder(3, 7);
 }
 else
 if (digitalRead(BINHDINH)==0)
 {
  myDFPlayer.playFolder(3, 8);
 }
 else
 if (digitalRead(BINHDUONG)==0)
 {
  myDFPlayer.playFolder(3, 9);
 }
 else
 if (digitalRead(BINHPHUOC)==0)
 {
  myDFPlayer.playFolder(3, 10);
 }
 else
 if (digitalRead(BINHTHUAN)==0)
 {
  myDFPlayer.playFolder(3, 11);
 }
 else
 if (digitalRead(CAMAU)==0)
 {
  myDFPlayer.playFolder(3, 12);
 }
 else
 if (digitalRead(CANTHO)==0)
 {
  myDFPlayer.playFolder(3, 13);
 }
 else
 if (digitalRead(CAOBANG)==0)
 {
  myDFPlayer.playFolder(3, 14);
 }
 else
 if (digitalRead(DANANG)==0)
 {
  myDFPlayer.playFolder(3, 15);
 }
 else
 if (digitalRead(DAKLAK)==0)
 {
  myDFPlayer.playFolder(3, 16);
 }
 else
 if (digitalRead(DAKNONG)==0)
 {
  myDFPlayer.playFolder(3, 17);
 }
 else
 if (digitalRead(DIENBIEN)==0)
 {
  myDFPlayer.playFolder(3, 18);
 }
 else
 if (digitalRead(DONGNAI)==0)
 {
  myDFPlayer.playFolder(3, 19);
 }
 else
 if (digitalRead(DONGTHAP)==0)
 {
  myDFPlayer.playFolder(3, 20);
 }
 else
 if (digitalRead(GIALAI)==0)
 {
  myDFPlayer.playFolder(3, 21);
 }
 else
 if (digitalRead(HAGIANG)==0)
 {
  myDFPlayer.playFolder(3, 22);
 }
 else
 if (digitalRead(HANAM)==0)
 {
  myDFPlayer.playFolder(3, 23);
 }
 else
 if (digitalRead(HANOI)==0)
 {
  myDFPlayer.playFolder(3, 24);
 }
 else
 if (digitalRead(HATINH)==0)
 {
  myDFPlayer.playFolder(3, 25);
 }
 else
 if (digitalRead(HAIDUONG)==0)
 {
  myDFPlayer.playFolder(3, 26);
 }
 else
 if (digitalRead(HAIPHONG)==0)
 {
  myDFPlayer.playFolder(3, 27);
 }
 else
 if (digitalRead(HAUGIANG)==0)
 {
  myDFPlayer.playFolder(3, 28);
 }
 else
 if (digitalRead(HOABINH)==0)
 {
  myDFPlayer.playFolder(3, 29);
 }
 else
 if (digitalRead(HUNGYEN)==0)
 {
  myDFPlayer.playFolder(3, 30);
 }
 else
 if (digitalRead(KHANHHOA)==0)
 {
  myDFPlayer.playFolder(3, 31);
 }
 else
 if (digitalRead(KIENGIANG)==0)
 {
  myDFPlayer.playFolder(3, 32);
 }
 else
 if (digitalRead(KONTUM)==0)
 {
  myDFPlayer.playFolder(3, 33);
 }
 else
 if (digitalRead(LAICHAU)==0)
 {
  myDFPlayer.playFolder(3, 34);
 }
 else
 if (digitalRead(LAMDONG)==0)
 {
  myDFPlayer.playFolder(3, 35);
 }
 else
 if (digitalRead(LANGSON)==0)
 {
  myDFPlayer.playFolder(3, 36);
 }
 else
 if (digitalRead(LAOCAI)==0)
 {
  myDFPlayer.playFolder(3, 37);
 }
 else
 if (digitalRead(LONGAN)==0)
 {
  myDFPlayer.playFolder(3, 38);
 }
 else
 if (digitalRead(NAMDINH)==0)
 {
  myDFPlayer.playFolder(3, 39);
 }
 else
 if (digitalRead(NGHEAN)==0)
 {
  myDFPlayer.playFolder(3, 40);
 }
 else
 if (digitalRead(NINHBINH)==0)
 {
  myDFPlayer.playFolder(3, 41);
 }
 else
 if (digitalRead(NINHTHUAN)==0)
 {
  myDFPlayer.playFolder(3, 42);
 }
 else
 if (digitalRead(PHUTHO)==0)
 {
  myDFPlayer.playFolder(3, 43);
 }
 else
 if (digitalRead(PHUYEN)==0)
 {
  myDFPlayer.playFolder(3, 44);
 }
 else
 if (digitalRead(QUANGBINH)==0)
 {
  myDFPlayer.playFolder(3, 45);
 }
 else
 if (digitalRead(QUANGNAM)==0)
 {
  myDFPlayer.playFolder(3, 46);
 }
 else
 if (digitalRead(QUANGNGAI)==0)
 {
  myDFPlayer.playFolder(3, 47);
 }
 else
 if (digitalRead(QUANGNINH)==0)
 {
  myDFPlayer.playFolder(3, 48);
 }
 else
 if (digitalRead(QUANGTRI)==0)
 {
  myDFPlayer.playFolder(3, 49);
 }
 else
 if (digitalRead(SOCTRANG)==0)
 {
  myDFPlayer.playFolder(3, 50);
 }
 else
 if (digitalRead(SONLA)==0)
 {
  myDFPlayer.playFolder(3, 51);
 }
 else
 if (digitalRead(TAYNINH)==0)
 {
  myDFPlayer.playFolder(3, 52);
 }
 else
 if (digitalRead(THAIBINH)==0)
 {
  myDFPlayer.playFolder(3, 53);
 }
 else
 if (digitalRead(THNGUYEN)==0)
 {
  myDFPlayer.playFolder(3, 54);
 }
 else
 if (digitalRead(THANHHOA)==0)
 {
  myDFPlayer.playFolder(3, 55);
 }
 else
 if (digitalRead(HUE)==0)
 {
  myDFPlayer.playFolder(3, 56);
 }
 if (digitalRead(TIENGIANG)==0)
 {
  myDFPlayer.playFolder(3, 57);
 }
 else
 if (digitalRead(TPHCM)==0)
 {
  myDFPlayer.playFolder(3, 58);
 }
 else
 if (digitalRead(TRAVINH)==0)
 {
  myDFPlayer.playFolder(3, 59);
 }
 else
 if (digitalRead(TQUANG)==0)
 {
  myDFPlayer.playFolder(3, 60);
 }
 else
 if (digitalRead(VINHLONG)==0)
 {
  myDFPlayer.playFolder(3, 61);
 }
 else
 if (digitalRead(VINHPHUC)==0)
 {
  myDFPlayer.playFolder(3, 62);
 }
 else
 if (digitalRead(YENBAI)==0)
 {
  myDFPlayer.playFolder(3, 63);
 }
 else
 if (digitalRead(HOANGSA)==0)
 {
  myDFPlayer.playFolder(3, 64);
 }
 else
 if (digitalRead(TRUONGSA)==0)
 {
  myDFPlayer.playFolder(3, 65);
 }
}

void DKTN()
{
 if (digitalRead(ANGIANG)==0)
 {
  myDFPlayer.playFolder(4, 1);
 }
 else
 if (digitalRead(BRVT)==0)
 {
  myDFPlayer.playFolder(4, 2);
 }
 else
 if (digitalRead(BACGIANG)==0)
 {
  myDFPlayer.playFolder(4, 3);
 }
 else
 if (digitalRead(BACKAN)==0)
 {
  myDFPlayer.playFolder(4, 4);
 }
 else
 if (digitalRead(BACLIEU)==0)
 {
  myDFPlayer.playFolder(4, 5);
 }
 else
 if (digitalRead(BACNINH)==0)
 {
  myDFPlayer.playFolder(4, 6);
 }
 else
 if (digitalRead(BENTRE)==0)
 {
  myDFPlayer.playFolder(4, 7);
 }
 else
 if (digitalRead(BINHDINH)==0)
 {
  myDFPlayer.playFolder(4, 8);
 }
 else
 if (digitalRead(BINHDUONG)==0)
 {
  myDFPlayer.playFolder(4, 9);
 }
 else
 if (digitalRead(BINHPHUOC)==0)
 {
  myDFPlayer.playFolder(4, 10);
 }
 else
 if (digitalRead(BINHTHUAN)==0)
 {
  myDFPlayer.playFolder(4, 11);
 }
 else
 if (digitalRead(CAMAU)==0)
 {
  myDFPlayer.playFolder(4, 12);
 }
 else
 if (digitalRead(CANTHO)==0)
 {
  myDFPlayer.playFolder(4, 13);
 }
 else
 if (digitalRead(CAOBANG)==0)
 {
  myDFPlayer.playFolder(4, 14);
 }
 else
 if (digitalRead(DANANG)==0)
 {
  myDFPlayer.playFolder(4, 15);
 }
 else
 if (digitalRead(DAKLAK)==0)
 {
  myDFPlayer.playFolder(4, 16);
 }
 else
 if (digitalRead(DAKNONG)==0)
 {
  myDFPlayer.playFolder(4, 17);
 }
 else
 if (digitalRead(DIENBIEN)==0)
 {
  myDFPlayer.playFolder(4, 18);
 }
 else
 if (digitalRead(DONGNAI)==0)
 {
  myDFPlayer.playFolder(4, 19);
 }
 else
 if (digitalRead(DONGTHAP)==0)
 {
  myDFPlayer.playFolder(4, 20);
 }
 else
 if (digitalRead(GIALAI)==0)
 {
  myDFPlayer.playFolder(4, 21);
 }
 else
 if (digitalRead(HAGIANG)==0)
 {
  myDFPlayer.playFolder(4, 22);
 }
 else
 if (digitalRead(HANAM)==0)
 {
  myDFPlayer.playFolder(4, 23);
 }
 else
 if (digitalRead(HANOI)==0)
 {
  myDFPlayer.playFolder(4, 24);
 }
 else
 if (digitalRead(HATINH)==0)
 {
  myDFPlayer.playFolder(4, 25);
 }
 else
 if (digitalRead(HAIDUONG)==0)
 {
  myDFPlayer.playFolder(4, 26);
 }
 else
 if (digitalRead(HAIPHONG)==0)
 {
  myDFPlayer.playFolder(4, 27);
 }
 else
 if (digitalRead(HAUGIANG)==0)
 {
  myDFPlayer.playFolder(4, 28);
 }
 else
 if (digitalRead(HOABINH)==0)
 {
  myDFPlayer.playFolder(4, 29);
 }
 else
 if (digitalRead(HUNGYEN)==0)
 {
  myDFPlayer.playFolder(4, 30);
 }
 else
 if (digitalRead(KHANHHOA)==0)
 {
  myDFPlayer.playFolder(4, 31);
 }
 else
 if (digitalRead(KIENGIANG)==0)
 {
  myDFPlayer.playFolder(4, 32);
 }
 else
 if (digitalRead(KONTUM)==0)
 {
  myDFPlayer.playFolder(4, 33);
 }
 else
 if (digitalRead(LAICHAU)==0)
 {
  myDFPlayer.playFolder(4, 34);
 }
 else
 if (digitalRead(LAMDONG)==0)
 {
  myDFPlayer.playFolder(4, 35);
 }
 else
 if (digitalRead(LANGSON)==0)
 {
  myDFPlayer.playFolder(4, 36);
 }
 else
 if (digitalRead(LAOCAI)==0)
 {
  myDFPlayer.playFolder(4, 37);
 }
 else
 if (digitalRead(LONGAN)==0)
 {
  myDFPlayer.playFolder(4, 38);
 }
 else
 if (digitalRead(NAMDINH)==0)
 {
  myDFPlayer.playFolder(4, 39);
 }
 else
 if (digitalRead(NGHEAN)==0)
 {
  myDFPlayer.playFolder(4, 40);
 }
 else
 if (digitalRead(NINHBINH)==0)
 {
  myDFPlayer.playFolder(4, 41);
 }
 else
 if (digitalRead(NINHTHUAN)==0)
 {
  myDFPlayer.playFolder(4, 42);
 }
 else
 if (digitalRead(PHUTHO)==0)
 {
  myDFPlayer.playFolder(4, 43);
 }
 else
 if (digitalRead(PHUYEN)==0)
 {
  myDFPlayer.playFolder(4, 44);
 }
 else
 if (digitalRead(QUANGBINH)==0)
 {
  myDFPlayer.playFolder(4, 45);
 }
 else
 if (digitalRead(QUANGNAM)==0)
 {
  myDFPlayer.playFolder(4, 46);
 }
 else
 if (digitalRead(QUANGNGAI)==0)
 {
  myDFPlayer.playFolder(4, 47);
 }
 else
 if (digitalRead(QUANGNINH)==0)
 {
  myDFPlayer.playFolder(4, 48);
 }
 else
 if (digitalRead(QUANGTRI)==0)
 {
  myDFPlayer.playFolder(4, 49);
 }
 else
 if (digitalRead(SOCTRANG)==0)
 {
  myDFPlayer.playFolder(4, 50);
 }
 else
 if (digitalRead(SONLA)==0)
 {
  myDFPlayer.playFolder(4, 51);
 }
 else
 if (digitalRead(TAYNINH)==0)
 {
  myDFPlayer.playFolder(4, 52);
 }
 else
 if (digitalRead(THAIBINH)==0)
 {
  myDFPlayer.playFolder(4, 53);
 }
 else
 if (digitalRead(THNGUYEN)==0)
 {
  myDFPlayer.playFolder(4, 54);
 }
 else
 if (digitalRead(THANHHOA)==0)
 {
  myDFPlayer.playFolder(4, 55);
 }
 else
 if (digitalRead(HUE)==0)
 {
  myDFPlayer.playFolder(4, 56);
 }
 if (digitalRead(TIENGIANG)==0)
 {
  myDFPlayer.playFolder(4, 57);
 }
 else
 if (digitalRead(TPHCM)==0)
 {
  myDFPlayer.playFolder(4, 58);
 }
 else
 if (digitalRead(TRAVINH)==0)
 {
  myDFPlayer.playFolder(4, 59);
 }
 else
 if (digitalRead(TQUANG)==0)
 {
  myDFPlayer.playFolder(4, 60);
 }
 else
 if (digitalRead(VINHLONG)==0)
 {
  myDFPlayer.playFolder(4, 61);
 }
 else
 if (digitalRead(VINHPHUC)==0)
 {
  myDFPlayer.playFolder(4, 62);
 }
 else
 if (digitalRead(YENBAI)==0)
 {
  myDFPlayer.playFolder(4, 63);
 }
}

void KINHTE()
{
 if (digitalRead(ANGIANG)==0)
 {
  myDFPlayer.playFolder(5, 1);
 }
 else
 if (digitalRead(BRVT)==0)
 {
  myDFPlayer.playFolder(5, 2);
 }
 else
 if (digitalRead(BACGIANG)==0)
 {
  myDFPlayer.playFolder(5, 3);
 }
 else
 if (digitalRead(BACKAN)==0)
 {
  myDFPlayer.playFolder(5, 4);
 }
 else
 if (digitalRead(BACLIEU)==0)
 {
  myDFPlayer.playFolder(5, 5);
 }
 else
 if (digitalRead(BACNINH)==0)
 {
  myDFPlayer.playFolder(5, 6);
 }
 else
 if (digitalRead(BENTRE)==0)
 {
  myDFPlayer.playFolder(5, 7);
 }
 else
 if (digitalRead(BINHDINH)==0)
 {
  myDFPlayer.playFolder(5, 8);
 }
 else
 if (digitalRead(BINHDUONG)==0)
 {
  myDFPlayer.playFolder(5, 9);
 }
 else
 if (digitalRead(BINHPHUOC)==0)
 {
  myDFPlayer.playFolder(5, 10);
 }
 else
 if (digitalRead(BINHTHUAN)==0)
 {
  myDFPlayer.playFolder(5, 11);
 }
 else
 if (digitalRead(CAMAU)==0)
 {
  myDFPlayer.playFolder(5, 12);
 }
 else
 if (digitalRead(CANTHO)==0)
 {
  myDFPlayer.playFolder(5, 13);
 }
 else
 if (digitalRead(CAOBANG)==0)
 {
  myDFPlayer.playFolder(5, 14);
 }
 else
 if (digitalRead(DANANG)==0)
 {
  myDFPlayer.playFolder(5, 15);
 }
 else
 if (digitalRead(DAKLAK)==0)
 {
  myDFPlayer.playFolder(5, 16);
 }
 else
 if (digitalRead(DAKNONG)==0)
 {
  myDFPlayer.playFolder(5, 17);
 }
 else
 if (digitalRead(DIENBIEN)==0)
 {
  myDFPlayer.playFolder(5, 18);
 }
 else
 if (digitalRead(DONGNAI)==0)
 {
  myDFPlayer.playFolder(5, 19);
 }
 else
 if (digitalRead(DONGTHAP)==0)
 {
  myDFPlayer.playFolder(5, 20);
 }
 else
 if (digitalRead(GIALAI)==0)
 {
  myDFPlayer.playFolder(5, 21);
 }
 else
 if (digitalRead(HAGIANG)==0)
 {
  myDFPlayer.playFolder(5, 22);
 }
 else
 if (digitalRead(HANAM)==0)
 {
  myDFPlayer.playFolder(5, 23);
 }
 else
 if (digitalRead(HANOI)==0)
 {
  myDFPlayer.playFolder(5, 24);
 }
 else
 if (digitalRead(HATINH)==0)
 {
  myDFPlayer.playFolder(5, 25);
 }
 else
 if (digitalRead(HAIDUONG)==0)
 {
  myDFPlayer.playFolder(5, 26);
 }
 else
 if (digitalRead(HAIPHONG)==0)
 {
  myDFPlayer.playFolder(5, 27);
 }
 else
 if (digitalRead(HAUGIANG)==0)
 {
  myDFPlayer.playFolder(5, 28);
 }
 else
 if (digitalRead(HOABINH)==0)
 {
  myDFPlayer.playFolder(5, 29);
 }
 else
 if (digitalRead(HUNGYEN)==0)
 {
  myDFPlayer.playFolder(5, 30);
 }
 else
 if (digitalRead(KHANHHOA)==0)
 {
  myDFPlayer.playFolder(5, 31);
 }
 else
 if (digitalRead(KIENGIANG)==0)
 {
  myDFPlayer.playFolder(5, 32);
 }
 else
 if (digitalRead(KONTUM)==0)
 {
  myDFPlayer.playFolder(5, 33);
 }
 else
 if (digitalRead(LAICHAU)==0)
 {
  myDFPlayer.playFolder(5, 34);
 }
 else
 if (digitalRead(LAMDONG)==0)
 {
  myDFPlayer.playFolder(5, 35);
 }
 else
 if (digitalRead(LANGSON)==0)
 {
  myDFPlayer.playFolder(5, 36);
 }
 else
 if (digitalRead(LAOCAI)==0)
 {
  myDFPlayer.playFolder(5, 37);
 }
 else
 if (digitalRead(LONGAN)==0)
 {
  myDFPlayer.playFolder(5, 38);
 }
 else
 if (digitalRead(NAMDINH)==0)
 {
  myDFPlayer.playFolder(5, 39);
 }
 else
 if (digitalRead(NGHEAN)==0)
 {
  myDFPlayer.playFolder(5, 40);
 }
 else
 if (digitalRead(NINHBINH)==0)
 {
  myDFPlayer.playFolder(5, 41);
 }
 else
 if (digitalRead(NINHTHUAN)==0)
 {
  myDFPlayer.playFolder(5, 42);
 }
 else
 if (digitalRead(PHUTHO)==0)
 {
  myDFPlayer.playFolder(5, 43);
 }
 else
 if (digitalRead(PHUYEN)==0)
 {
  myDFPlayer.playFolder(5, 44);
 }
 else
 if (digitalRead(QUANGBINH)==0)
 {
  myDFPlayer.playFolder(5, 45);
 }
 else
 if (digitalRead(QUANGNAM)==0)
 {
  myDFPlayer.playFolder(5, 46);
 }
 else
 if (digitalRead(QUANGNGAI)==0)
 {
  myDFPlayer.playFolder(5, 47);
 }
 else
 if (digitalRead(QUANGNINH)==0)
 {
  myDFPlayer.playFolder(5, 48);
 }
 else
 if (digitalRead(QUANGTRI)==0)
 {
  myDFPlayer.playFolder(5, 49);
 }
 else
 if (digitalRead(SOCTRANG)==0)
 {
  myDFPlayer.playFolder(5, 50);
 }
 else
 if (digitalRead(SONLA)==0)
 {
  myDFPlayer.playFolder(5, 51);
 }
 else
 if (digitalRead(TAYNINH)==0)
 {
  myDFPlayer.playFolder(5, 52);
 }
 else
 if (digitalRead(THAIBINH)==0)
 {
  myDFPlayer.playFolder(5, 53);
 }
 else
 if (digitalRead(THNGUYEN)==0)
 {
  myDFPlayer.playFolder(5, 54);
 }
 else
 if (digitalRead(THANHHOA)==0)
 {
  myDFPlayer.playFolder(5, 55);
 }
 else
 if (digitalRead(HUE)==0)
 {
  myDFPlayer.playFolder(5, 56);
 }
 if (digitalRead(TIENGIANG)==0)
 {
  myDFPlayer.playFolder(5, 57);
 }
 else
 if (digitalRead(TPHCM)==0)
 {
  myDFPlayer.playFolder(5, 58);
 }
 else
 if (digitalRead(TRAVINH)==0)
 {
  myDFPlayer.playFolder(5, 59);
 }
 else
 if (digitalRead(TQUANG)==0)
 {
  myDFPlayer.playFolder(5, 60);
 }
 else
 if (digitalRead(VINHLONG)==0)
 {
  myDFPlayer.playFolder(5, 61);
 }
 else
 if (digitalRead(VINHPHUC)==0)
 {
  myDFPlayer.playFolder(5, 62);
 }
 else
 if (digitalRead(YENBAI)==0)
 {
  myDFPlayer.playFolder(5, 63);
 }
}

void DIAHINH()
{
 if (digitalRead(ANGIANG)==0)
 {
  myDFPlayer.playFolder(6, 1);
 }
 else
 if (digitalRead(BRVT)==0)
 {
  myDFPlayer.playFolder(6, 2);
 }
 else
 if (digitalRead(BACGIANG)==0)
 {
  myDFPlayer.playFolder(6, 3);
 }
 else
 if (digitalRead(BACKAN)==0)
 {
  myDFPlayer.playFolder(6, 4);
 }
 else
 if (digitalRead(BACLIEU)==0)
 {
  myDFPlayer.playFolder(6, 5);
 }
 else
 if (digitalRead(BACNINH)==0)
 {
  myDFPlayer.playFolder(6, 6);
 }
 else
 if (digitalRead(BENTRE)==0)
 {
  myDFPlayer.playFolder(6, 7);
 }
 else
 if (digitalRead(BINHDINH)==0)
 {
  myDFPlayer.playFolder(6, 8);
 }
 else
 if (digitalRead(BINHDUONG)==0)
 {
  myDFPlayer.playFolder(6, 9);
 }
 else
 if (digitalRead(BINHPHUOC)==0)
 {
  myDFPlayer.playFolder(6, 10);
 }
 else
 if (digitalRead(BINHTHUAN)==0)
 {
  myDFPlayer.playFolder(6, 11);
 }
 else
 if (digitalRead(CAMAU)==0)
 {
  myDFPlayer.playFolder(6, 12);
 }
 else
 if (digitalRead(CANTHO)==0)
 {
  myDFPlayer.playFolder(6, 13);
 }
 else
 if (digitalRead(CAOBANG)==0)
 {
  myDFPlayer.playFolder(6, 14);
 }
 else
 if (digitalRead(DANANG)==0)
 {
  myDFPlayer.playFolder(6, 15);
 }
 else
 if (digitalRead(DAKLAK)==0)
 {
  myDFPlayer.playFolder(6, 16);
 }
 else
 if (digitalRead(DAKNONG)==0)
 {
  myDFPlayer.playFolder(6, 17);
 }
 else
 if (digitalRead(DIENBIEN)==0)
 {
  myDFPlayer.playFolder(6, 18);
 }
 else
 if (digitalRead(DONGNAI)==0)
 {
  myDFPlayer.playFolder(6, 19);
 }
 else
 if (digitalRead(DONGTHAP)==0)
 {
  myDFPlayer.playFolder(6, 20);
 }
 else
 if (digitalRead(GIALAI)==0)
 {
  myDFPlayer.playFolder(6, 21);
 }
 else
 if (digitalRead(HAGIANG)==0)
 {
  myDFPlayer.playFolder(6, 22);
 }
 else
 if (digitalRead(HANAM)==0)
 {
  myDFPlayer.playFolder(6, 23);
 }
 else
 if (digitalRead(HANOI)==0)
 {
  myDFPlayer.playFolder(6, 24);
 }
 else
 if (digitalRead(HATINH)==0)
 {
  myDFPlayer.playFolder(6, 25);
 }
 else
 if (digitalRead(HAIDUONG)==0)
 {
  myDFPlayer.playFolder(6, 26);
 }
 else
 if (digitalRead(HAIPHONG)==0)
 {
  myDFPlayer.playFolder(6, 27);
 }
 else
 if (digitalRead(HAUGIANG)==0)
 {
  myDFPlayer.playFolder(6, 28);
 }
 else
 if (digitalRead(HOABINH)==0)
 {
  myDFPlayer.playFolder(6, 29);
 }
 else
 if (digitalRead(HUNGYEN)==0)
 {
  myDFPlayer.playFolder(6, 30);
 }
 else
 if (digitalRead(KHANHHOA)==0)
 {
  myDFPlayer.playFolder(6, 31);
 }
 else
 if (digitalRead(KIENGIANG)==0)
 {
  myDFPlayer.playFolder(6, 32);
 }
 else
 if (digitalRead(KONTUM)==0)
 {
  myDFPlayer.playFolder(6, 33);
 }
 else
 if (digitalRead(LAICHAU)==0)
 {
  myDFPlayer.playFolder(6, 34);
 }
 else
 if (digitalRead(LAMDONG)==0)
 {
  myDFPlayer.playFolder(6, 35);
 }
 else
 if (digitalRead(LANGSON)==0)
 {
  myDFPlayer.playFolder(6, 36);
 }
 else
 if (digitalRead(LAOCAI)==0)
 {
  myDFPlayer.playFolder(6, 37);
 }
 else
 if (digitalRead(LONGAN)==0)
 {
  myDFPlayer.playFolder(6, 38);
 }
 else
 if (digitalRead(NAMDINH)==0)
 {
  myDFPlayer.playFolder(6, 39);
 }
 else
 if (digitalRead(NGHEAN)==0)
 {
  myDFPlayer.playFolder(6, 40);
 }
 else
 if (digitalRead(NINHBINH)==0)
 {
  myDFPlayer.playFolder(6, 41);
 }
 else
 if (digitalRead(NINHTHUAN)==0)
 {
  myDFPlayer.playFolder(6, 42);
 }
 else
 if (digitalRead(PHUTHO)==0)
 {
  myDFPlayer.playFolder(6, 43);
 }
 else
 if (digitalRead(PHUYEN)==0)
 {
  myDFPlayer.playFolder(6, 44);
 }
 else
 if (digitalRead(QUANGBINH)==0)
 {
  myDFPlayer.playFolder(6, 45);
 }
 else
 if (digitalRead(QUANGNAM)==0)
 {
  myDFPlayer.playFolder(6, 46);
 }
 else
 if (digitalRead(QUANGNGAI)==0)
 {
  myDFPlayer.playFolder(6, 47);
 }
 else
 if (digitalRead(QUANGNINH)==0)
 {
  myDFPlayer.playFolder(6, 48);
 }
 else
 if (digitalRead(QUANGTRI)==0)
 {
  myDFPlayer.playFolder(6, 49);
 }
 else
 if (digitalRead(SOCTRANG)==0)
 {
  myDFPlayer.playFolder(6, 50);
 }
 else
 if (digitalRead(SONLA)==0)
 {
  myDFPlayer.playFolder(6, 51);
 }
 else
 if (digitalRead(TAYNINH)==0)
 {
  myDFPlayer.playFolder(6, 52);
 }
 else
 if (digitalRead(THAIBINH)==0)
 {
  myDFPlayer.playFolder(6, 53);
 }
 else
 if (digitalRead(THNGUYEN)==0)
 {
  myDFPlayer.playFolder(6, 54);
 }
 else
 if (digitalRead(THANHHOA)==0)
 {
  myDFPlayer.playFolder(6, 55);
 }
 else
 if (digitalRead(HUE)==0)
 {
  myDFPlayer.playFolder(6, 56);
 }
 if (digitalRead(TIENGIANG)==0)
 {
  myDFPlayer.playFolder(6, 57);
 }
 else
 if (digitalRead(TPHCM)==0)
 {
  myDFPlayer.playFolder(6, 58);
 }
 else
 if (digitalRead(TRAVINH)==0)
 {
  myDFPlayer.playFolder(6, 59);
 }
 else
 if (digitalRead(TQUANG)==0)
 {
  myDFPlayer.playFolder(6, 60);
 }
 else
 if (digitalRead(VINHLONG)==0)
 {
  myDFPlayer.playFolder(6, 61);
 }
 else
 if (digitalRead(VINHPHUC)==0)
 {
  myDFPlayer.playFolder(6, 62);
 }
 else
 if (digitalRead(YENBAI)==0)
 {
  myDFPlayer.playFolder(6, 63);
 }
}
void TAYBACBO()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==1)&&(TBB1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 37);
  TBB1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==1)&&(TBB2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 63);
  TBB2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==1)&&(TBB3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 34);
  TBB3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==1)&&(TBB4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 18);
  TBB4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==1)&&(TBB5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 51);
  TBB5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==1)&&(TBB6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 29);
  TBB6=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==1)&&(TBB1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 37);
  TBB1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==1)&&(TBB2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 63);
  TBB2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==1)&&(TBB3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 34);
  TBB3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==1)&&(TBB4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 18);
  TBB4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==1)&&(TBB5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 51);
  TBB5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==1)&&(TBB6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 29);
  TBB6=3;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==1)&&(TBB1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 37);
  TBB1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==1)&&(TBB2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 63);
  TBB2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==1)&&(TBB3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 34);
  TBB3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==1)&&(TBB4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 18);
  TBB4=4;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==1)&&(TBB5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 51);
  TBB5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==1)&&(TBB6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 29);
  TBB6=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==1)&&(TBB1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 37);
  TBB1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==1)&&(TBB2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 63);
  TBB2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==1)&&(TBB3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 34);
  TBB3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==1)&&(TBB4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 18);
  TBB4=5;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==1)&&(TBB5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 51);
  TBB5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==1)&&(TBB6==4))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 29);
  TBB6=5;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==1)&&(TBB1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 37);
  TBB1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==1)&&(TBB2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 63);
  TBB2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==1)&&(TBB3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 34);
  TBB3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==1)&&(TBB4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 18);
  TBB4=1;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==1)&&(TBB5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 51);
  TBB5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==1)&&(TBB6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 29);
  TBB6=1;
 }
}
void DONGBACBO()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==2)&&(DBB1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 22);
  DBB1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==2)&&(DBB2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 60);
  DBB2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==2)&&(DBB3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 43);
  DBB3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==2)&&(DBB4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 54);
  DBB4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==2)&&(DBB5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 4);
  DBB5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==2)&&(DBB6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 14);
  DBB6=2;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==2)&&(DBB7==1))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(2, 36);
  DBB7=2;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==2)&&(DBB8==1))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(2, 3);
  DBB8=2;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==2)&&(DBB9==1))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(2, 48);
  DBB9=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==2)&&(DBB1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 22);
  DBB1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==2)&&(DBB2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 60);
  DBB2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==2)&&(DBB3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 43);
  DBB3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==2)&&(DBB4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 54);
  DBB4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==2)&&(DBB5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 4);
  DBB5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==2)&&(DBB6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 14);
  DBB6=3;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==2)&&(DBB7==2))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(3, 36);
  DBB7=3;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==2)&&(DBB8==2))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(3, 3);
  DBB8=3;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==2)&&(DBB9==2))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(3, 48);
  DBB9=3;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==2)&&(DBB1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 22);
  DBB1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==2)&&(DBB2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 60);
  DBB2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==2)&&(DBB3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 43);
  DBB3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==2)&&(DBB4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 54);
  DBB4=4;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==2)&&(DBB5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 4);
  DBB5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==2)&&(DBB6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 14);
  DBB6=4;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==2)&&(DBB7==3))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(4, 36);
  DBB7=4;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==2)&&(DBB8==3))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(4, 3);
  DBB8=4;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==2)&&(DBB9==3))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(4, 48);
  DBB9=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==2)&&(DBB1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 22);
  DBB1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==2)&&(DBB2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 60);
  DBB2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==2)&&(DBB3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 43);
  DBB3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==2)&&(DBB4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 54);
  DBB4=5;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==2)&&(DBB5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 4);
  DBB5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==1)&&(DBB6==4))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 14);
  DBB6=5;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==2)&&(DBB7==4))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(5, 36);
  DBB7=5;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==2)&&(DBB8==4))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(5, 3);
  DBB8=5;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==2)&&(DBB9==4))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(5, 48);
  DBB9=5;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==2)&&(DBB1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 22);
  DBB1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==2)&&(DBB2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 60);
  DBB2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==2)&&(DBB3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 43);
  DBB3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==2)&&(DBB4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 54);
  DBB4=1;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==2)&&(DBB5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 4);
  DBB5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==2)&&(DBB6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 14);
  DBB6=1;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==2)&&(DBB7==5))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(6, 36);
  DBB7=1;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==2)&&(DBB8==5))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(6, 3);
  DBB8=1;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==2)&&(DBB9==5))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(6, 48);
  DBB9=1;
 }
}
void DBSONGHONG()
{
 //LAN1DBSCL
 if ((digitalRead(LANGSON)==0)&&(demvungmien==3)&&(DBSH1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 24);
  DBSH1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==3)&&(DBSH2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 27);
  DBSH2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==3)&&(DBSH3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 62);
  DBSH3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==3)&&(DBSH4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 6);
  DBSH4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==3)&&(DBSH5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 30);
  DBSH5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==3)&&(DBSH6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 26);
  DBSH6=2;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==3)&&(DBSH7==1))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(2, 53);
  DBSH7=2;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==3)&&(DBSH8==1))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(2, 39);
  DBSH8=2;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==3)&&(DBSH9==1))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(2, 41);
  DBSH9=2;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==3)&&(DBSH10==1))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(2, 23);
  DBSH10=2;
 } 
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==3)&&(DBSH1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 24);
  DBSH1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==3)&&(DBSH2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 27);
  DBSH2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==3)&&(DBSH3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 62);
  DBSH3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==3)&&(DBSH4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 6);
  DBSH4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==3)&&(DBSH5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 30);
  DBSH5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==3)&&(DBSH6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 26);
  DBSH6=3;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==3)&&(DBSH7==2))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(3, 53);
  DBSH7=3;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==3)&&(DBSH8==2))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(3, 39);
  DBSH8=3;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==3)&&(DBSH9==2))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(3, 41);
  DBSH9=3;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==3)&&(DBSH10==2))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(3, 23);
  DBSH10=3;
 } 
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==3)&&(DBSH1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 24);
  DBSH1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==3)&&(DBSH2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 27);
  DBSH2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==3)&&(DBSH3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 62);
  DBSH3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==3)&&(DBSH4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 6);
  DBSH4=4;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==3)&&(DBSH5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 30);
  DBSH5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==3)&&(DBSH6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 26);
  DBSH6=4;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==3)&&(DBSH7==3))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(4, 53);
  DBSH7=4;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==3)&&(DBSH8==3))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(4, 39);
  DBSH8=4;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==3)&&(DBSH9==3))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(4, 41);
  DBSH9=4;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==3)&&(DBSH10==3))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(4, 23);
  DBSH10=4;
 } 
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==3)&&(DBSH1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 24);
  DBSH1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==3)&&(DBSH2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 27);
  DBSH2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==3)&&(DBSH3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 62);
  DBSH3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==3)&&(DBSH4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 6);
  DBSH4=5;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==3)&&(DBSH5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 30);
  DBSH5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==3)&&(DBSH6==4))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 26);
  DBSH6=5;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==3)&&(DBSH7==4))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(5, 53);
  DBSH7=5;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==3)&&(DBSH8==4))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(5, 39);
  DBSH8=5;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==3)&&(DBSH9==4))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(5, 41);
  DBSH9=5;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==3)&&(DBSH10==4))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(5, 23);
  DBSH10=5;
 } 
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==3)&&(DBSH1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 24);
  DBSH1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==3)&&(DBSH2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 27);
  DBSH2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==3)&&(DBSH3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 62);
  DBSH3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==3)&&(DBSH4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 6);
  DBSH4=1;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==3)&&(DBSH5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 30);
  DBSH5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==3)&&(DBSH6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 26);
  DBSH6=1;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==3)&&(DBSH7==5))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(6, 53);
  DBSH7=1;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==3)&&(DBSH8==5))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(6, 39);
  DBSH8=1;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==3)&&(DBSH9==5))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(6, 41);
  DBSH9=1;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==3)&&(DBSH10==5))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(6, 23);
  DBSH10=1;
 } 
}
void BACTRUNGBO()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==4)&&(BTB1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 55);
  BTB1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==4)&&(BTB2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 40);
  BTB2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==4)&&(BTB3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 25);
  BTB3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==4)&&(BTB4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 45);
  BTB4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==4)&&(BTB5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 49);
  BTB5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==4)&&(BTB6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 56);
  BTB6=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==4)&&(BTB1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 55);
  BTB1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==4)&&(BTB2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 40);
  BTB2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==4)&&(BTB3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 25);
  BTB3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==1)&&(BTB4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 45);
  BTB4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==4)&&(BTB5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 49);
  BTB5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==4)&&(BTB6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 56);
  BTB6=3;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==4)&&(BTB1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 55);
  BTB1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==4)&&(BTB2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 40);
  BTB2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==4)&&(BTB3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 25);
  BTB3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==4)&&(BTB4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 45);
  BTB4=4;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==4)&&(BTB5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 49);
  BTB5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==4)&&(BTB6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 56);
  BTB6=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==4)&&(BTB1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 55);
  BTB1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==4)&&(BTB2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 40);
  BTB2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==4)&&(BTB3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 25);
  BTB3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==4)&&(BTB4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 45);
  BTB4=5;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==4)&&(BTB5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 49);
  BTB5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==4)&&(BTB6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 56);
  BTB6=2;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==4)&&(BTB1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 55);
  BTB1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==4)&&(BTB2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 40);
  BTB2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==4)&&(BTB3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 25);
  BTB3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==4)&&(BTB4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 45);
  BTB4=1;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==4)&&(BTB5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 49);
  BTB5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==4)&&(BTB6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 56);
  BTB6=1;
 }
}
void DHNAMTRUNGBO()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==5)&&(DHNTB1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 15);
  DHNTB1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==5)&&(DHNTB2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 46);
  DHNTB2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==5)&&(DHNTB3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 47);
  DHNTB3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==5)&&(DHNTB4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 8);
  DHNTB4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==5)&&(DHNTB5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 44);
  DHNTB5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==5)&&(DHNTB6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 31);
  DHNTB6=2;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==5)&&(DHNTB7==1))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(2, 42);
  DHNTB7=2;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==5)&&(DHNTB8==1))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(2, 11);
  DHNTB8=2;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==5)&&(DHNTB9==1))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(2, 64);
  DHNTB9=2;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==5)&&(DHNTB10==1))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(2, 65);
  DHNTB10=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==5)&&(DHNTB1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 15);
  DHNTB1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==5)&&(DHNTB2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 46);
  DHNTB2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==5)&&(DHNTB3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 47);
  DHNTB3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==5)&&(DHNTB4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 8);
  DHNTB4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==5)&&(DHNTB5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 44);
  DHNTB5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==5)&&(DHNTB6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 31);
  DHNTB6=3;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==5)&&(DHNTB7==2))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(3, 42);
  DHNTB7=3;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==5)&&(DHNTB8==2))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(3, 11);
  DHNTB8=3;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==5)&&(DHNTB9==2))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(6, 64);
  DHNTB9=1;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==5)&&(DHNTB10==2))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(6, 65);
  DHNTB10=1;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==5)&&(DHNTB1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 15);
  DHNTB1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==5)&&(DHNTB2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 46);
  DHNTB2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==5)&&(DHNTB3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 47);
  DHNTB3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==5)&&(DHNTB4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 8);
  DHNTB4=4;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==5)&&(DHNTB5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 44);
  DHNTB5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==5)&&(DHNTB6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 31);
  DHNTB6=4;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==5)&&(DHNTB7==3))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(4, 42);
  DHNTB7=4;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==5)&&(DHNTB8==3))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(4, 11);
  DHNTB8=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==5)&&(DHNTB1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 15);
  DHNTB1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==5)&&(DHNTB2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 46);
  DHNTB2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==5)&&(DHNTB3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 47);
  DHNTB3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==5)&&(DHNTB4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 8);
  DHNTB4=5;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==5)&&(DHNTB5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 44);
  DHNTB5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==5)&&(DHNTB6==4))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 31);
  DHNTB6=5;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==5)&&(DHNTB7==4))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(5, 42);
  DHNTB7=5;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==5)&&(DHNTB8==4))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(5, 11);
  DHNTB8=5;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==5)&&(DHNTB1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 15);
  DHNTB1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==5)&&(DHNTB2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 46);
  DHNTB2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==5)&&(DHNTB3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 47);
  DHNTB3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==5)&&(DHNTB4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 8);
  DHNTB4=1;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==5)&&(DHNTB5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 44);
  DHNTB5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==5)&&(DHNTB6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 31);
  DHNTB6=1;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==5)&&(DHNTB7==5))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(6, 42);
  DHNTB7=1;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==5)&&(DHNTB8==5))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(6, 11);
  DHNTB8=1;
 }
}
void TAYNGUYEN()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==6)&&(TN1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 33);
  TN1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==6)&&(TN2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 21);
  TN2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==6)&&(TN3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 16);
  TN3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==6)&&(TN4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 17);
  TN4=2;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==6)&&(TN5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 35);
  TN5=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==6)&&(TN1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 33);
  TN1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==6)&&(TN2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 21);
  TN2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==6)&&(TN3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 16);
  TN3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==6)&&(TN4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 17);
  TN4=3;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==6)&&(TN5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 35);
  TN5=3;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==6)&&(TN1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 33);
  TN1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==6)&&(TN2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 21);
  TN2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==6)&&(TN3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 16);
  TN3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==6)&&(TN4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 17);
  TN4=4;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==6)&&(TN5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 35);
  TN5=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==6)&&(TN1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 33);
  TN1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==6)&&(TN2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 21);
  TN2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==6)&&(TN3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 16);
  TN3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==6)&&(TN4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 17);
  TN4=5;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==6)&&(TN5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 35);
  TN5=5;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==6)&&(TN1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 33);
  TN1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==6)&&(TN2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 21);
  TN2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==6)&&(TN3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 16);
  TN3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==6)&&(TN4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 17);
  TN4=1;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==6)&&(TN5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 35);
  TN5=1;
 }
}
void DONGNAMBO()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==7)&&(DNB1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 58);
  DNB1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==7)&&(DNB2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 19);
  DNB2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==7)&&(DNB3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 2);
  DNB3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==7)&&(DNB4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 9);
  DNB4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==7)&&(DNB5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 10);
  DNB5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==7)&&(DNB6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 52);
  DNB6=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==7)&&(DNB1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 58);
  DNB1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==7)&&(DNB2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 19);
  DNB2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==7)&&(DNB3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 2);
  DNB3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==7)&&(DNB4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 9);
  DNB4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==7)&&(DNB5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 10);
  DNB5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==7)&&(DNB6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 52);
  DNB6=3;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==7)&&(DNB1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 58);
  DNB1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==7)&&(DNB2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 19);
  DNB2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==7)&&(DNB3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 2);
  DNB3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==7)&&(DNB4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 9);
  DNB4=4;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==7)&&(DNB5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 10);
  DNB5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==7)&&(DNB6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 52);
  DNB6=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==7)&&(DNB1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 58);
  DNB1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==7)&&(DNB2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 19);
  DNB2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==7)&&(DNB3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 2);
  DNB3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==7)&&(DNB4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 9);
  DNB4=5;
 }
 if ((digitalRead(DIENBIEN)==0)&&(demvungmien==7)&&(DNB5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 10);
  DNB5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==7)&&(DNB6==4))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 52);
  DNB6=5;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==7)&&(DNB1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 58);
  DNB1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==7)&&(DNB2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 19);
  DNB2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==7)&&(DNB3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 2);
  DNB3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==7)&&(DNB4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 9);
  DNB4=1;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==7)&&(DNB5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 10);
  DNB5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==7)&&(DNB6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 52);
  DNB6=1;
 }
}
void DBSONGCUULONG()
{
 //LAN1
 if ((digitalRead(LANGSON)==0)&&(demvungmien==8)&&(DBSCL1==1))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(2, 13);
  DBSCL1=2;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==8)&&(DBSCL2==1))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(2, 38);
  DBSCL2=2;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==8)&&(DBSCL3==1))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(2, 57);
  DBSCL3=2;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==8)&&(DBSCL4==1))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(2, 7);
  DBSCL4=2;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==8)&&(DBSCL5==1))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(2, 61);
  DBSCL5=2;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==8)&&(DBSCL6==1))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(2, 59);
  DBSCL6=2;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==8)&&(DBSCL7==1))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(2, 20);
  DBSCL7=2;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==8)&&(DBSCL8==1))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(2, 1);
  DBSCL8=2;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==8)&&(DBSCL9==1))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(2, 32);
  DBSCL9=2;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==8)&&(DBSCL10==1))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(2, 28);
  DBSCL10=2;
 }
 if ((digitalRead(THNGUYEN)==0)&&(demvungmien==8)&&(DBSCL11==1))
 {
  while (digitalRead(THNGUYEN)==0){}
  myDFPlayer.playFolder(2, 50);
  DBSCL11=2;
 }
 if ((digitalRead(BACKAN)==0)&&(demvungmien==8)&&(DBSCL12==1))
 {
  while (digitalRead(BACKAN)==0){}
  myDFPlayer.playFolder(2, 5);
  DBSCL12=2;
 } 
 if ((digitalRead(CAOBANG)==0)&&(demvungmien==8)&&(DBSCL13==1))
 {
  while (digitalRead(CAOBANG)==0){}
  myDFPlayer.playFolder(2, 12);
  DBSCL13=2;
 }
 //LAN2
 if ((digitalRead(LANGSON)==0)&&(demvungmien==8)&&(DBSCL1==2))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(3, 13);
  DBSCL1=3;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==8)&&(DBSCL2==2))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(3, 38);
  DBSCL2=3;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==8)&&(DBSCL3==2))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(3, 57);
  DBSCL3=3;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==8)&&(DBSCL4==2))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(3, 7);
  DBSCL4=3;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==8)&&(DBSCL5==2))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(3, 61);
  DBSCL5=3;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==8)&&(DBSCL6==2))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(3, 59);
  DBSCL6=3;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==8)&&(DBSCL7==2))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(3, 20);
  DBSCL7=3;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==8)&&(DBSCL8==2))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(3, 1);
  DBSCL8=3;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==8)&&(DBSCL9==2))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(3, 32);
  DBSCL9=3;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==8)&&(DBSCL10==2))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(3, 28);
  DBSCL10=3;
 }
 if ((digitalRead(THNGUYEN)==0)&&(demvungmien==8)&&(DBSCL11==2))
 {
  while (digitalRead(THNGUYEN)==0){}
  myDFPlayer.playFolder(3, 50);
  DBSCL11=3;
 }
 if ((digitalRead(BACKAN)==0)&&(demvungmien==8)&&(DBSCL12==2))
 {
  while (digitalRead(BACKAN)==0){}
  myDFPlayer.playFolder(3, 5);
  DBSCL12=3;
 } 
 if ((digitalRead(CAOBANG)==0)&&(demvungmien==8)&&(DBSCL13==2))
 {
  while (digitalRead(CAOBANG)==0){}
  myDFPlayer.playFolder(3, 12);
  DBSCL13=3;
 }
 //LAN3
 if ((digitalRead(LANGSON)==0)&&(demvungmien==8)&&(DBSCL1==3))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(4, 13);
  DBSCL1=4;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==8)&&(DBSCL2==3))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(4, 38);
  DBSCL2=4;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==8)&&(DBSCL3==3))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(4, 57);
  DBSCL3=4;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==8)&&(DBSCL4==3))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(4, 7);
  DBSCL4=4;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==8)&&(DBSCL5==3))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(4, 61);
  DBSCL5=4;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==8)&&(DBSCL6==3))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(4, 59);
  DBSCL6=4;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==8)&&(DBSCL7==3))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(4, 20);
  DBSCL7=4;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==8)&&(DBSCL8==3))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(4, 1);
  DBSCL8=4;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==8)&&(DBSCL9==3))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(4, 32);
  DBSCL9=4;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==8)&&(DBSCL10==3))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(4, 28);
  DBSCL10=4;
 }
 if ((digitalRead(THNGUYEN)==0)&&(demvungmien==8)&&(DBSCL11==3))
 {
  while (digitalRead(THNGUYEN)==0){}
  myDFPlayer.playFolder(4, 50);
  DBSCL11=4;
 }
 if ((digitalRead(BACKAN)==0)&&(demvungmien==8)&&(DBSCL12==3))
 {
  while (digitalRead(BACKAN)==0){}
  myDFPlayer.playFolder(4, 5);
  DBSCL12=4;
 } 
 if ((digitalRead(CAOBANG)==0)&&(demvungmien==8)&&(DBSCL13==3))
 {
  while (digitalRead(CAOBANG)==0){}
  myDFPlayer.playFolder(4, 12);
  DBSCL13=4;
 }
 //LAN4
 if ((digitalRead(LANGSON)==0)&&(demvungmien==8)&&(DBSCL1==4))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(5, 13);
  DBSCL1=5;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==8)&&(DBSCL2==4))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(5, 38);
  DBSCL2=5;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==8)&&(DBSCL3==4))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(5, 57);
  DBSCL3=5;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==8)&&(DBSCL4==4))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(5, 7);
  DBSCL4=5;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==8)&&(DBSCL5==4))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(5, 61);
  DBSCL5=5;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==8)&&(DBSCL6==4))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(5, 59);
  DBSCL6=5;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==8)&&(DBSCL7==4))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(5, 20);
  DBSCL7=5;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==8)&&(DBSCL8==4))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(5, 1);
  DBSCL8=5;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==8)&&(DBSCL9==4))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(5, 32);
  DBSCL9=5;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==8)&&(DBSCL10==4))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(5, 28);
  DBSCL10=5;
 }
 if ((digitalRead(THNGUYEN)==0)&&(demvungmien==8)&&(DBSCL11==4))
 {
  while (digitalRead(THNGUYEN)==0){}
  myDFPlayer.playFolder(5, 50);
  DBSCL11=5;
 }
 if ((digitalRead(BACKAN)==0)&&(demvungmien==8)&&(DBSCL12==4))
 {
  while (digitalRead(BACKAN)==0){}
  myDFPlayer.playFolder(5, 5);
  DBSCL12=5;
 } 
 if ((digitalRead(CAOBANG)==0)&&(demvungmien==8)&&(DBSCL13==4))
 {
  while (digitalRead(CAOBANG)==0){}
  myDFPlayer.playFolder(5, 12);
  DBSCL13=5;
 }
 //LAN5
 if ((digitalRead(LANGSON)==0)&&(demvungmien==8)&&(DBSCL1==5))
 {
  while (digitalRead(LANGSON)==0){}
  myDFPlayer.playFolder(6, 13);
  DBSCL1=1;
 }
 if ((digitalRead(BACGIANG)==0)&&(demvungmien==8)&&(DBSCL2==5))
 {
  while (digitalRead(BACGIANG)==0){}
  myDFPlayer.playFolder(6, 38);
  DBSCL2=1;
 }
 if ((digitalRead(YENBAI)==0)&&(demvungmien==8)&&(DBSCL3==5))
 {
  while (digitalRead(YENBAI)==0){}
  myDFPlayer.playFolder(6, 57);
  DBSCL3=1;
 }
 if ((digitalRead(LAICHAU)==0)&&(demvungmien==8)&&(DBSCL4==5))
 {
  while (digitalRead(LAICHAU)==0){}
  myDFPlayer.playFolder(6, 7);
  DBSCL4=1;
 }
  if ((digitalRead(DIENBIEN)==0)&&(demvungmien==8)&&(DBSCL5==5))
 {
  while (digitalRead(DIENBIEN)==0){}
  myDFPlayer.playFolder(6, 61);
  DBSCL5=1;
 }
 if ((digitalRead(SONLA)==0)&&(demvungmien==8)&&(DBSCL6==5))
 {
  while (digitalRead(SONLA)==0){}
  myDFPlayer.playFolder(6, 59);
  DBSCL6=1;
 }
 if ((digitalRead(HOABINH)==0)&&(demvungmien==8)&&(DBSCL7==5))
 {
  while (digitalRead(HOABINH)==0){}
  myDFPlayer.playFolder(6, 20);
  DBSCL7=1;
 }
 if ((digitalRead(HAGIANG)==0)&&(demvungmien==8)&&(DBSCL8==5))
 {
  while (digitalRead(HAGIANG)==0){}
  myDFPlayer.playFolder(6, 1);
  DBSCL8=1;
 }
 if ((digitalRead(TQUANG)==0)&&(demvungmien==8)&&(DBSCL9==5))
 {
  while (digitalRead(TQUANG)==0){}
  myDFPlayer.playFolder(6, 32);
  DBSCL9=1;
 } 
 if ((digitalRead(PHUTHO)==0)&&(demvungmien==8)&&(DBSCL10==5))
 {
  while (digitalRead(PHUTHO)==0){}
  myDFPlayer.playFolder(6, 28);
  DBSCL10=1;
 }
 if ((digitalRead(THNGUYEN)==0)&&(demvungmien==8)&&(DBSCL11==5))
 {
  while (digitalRead(THNGUYEN)==0){}
  myDFPlayer.playFolder(6, 50);
  DBSCL11=1;
 }
 if ((digitalRead(BACKAN)==0)&&(demvungmien==8)&&(DBSCL12==5))
 {
  while (digitalRead(BACKAN)==0){}
  myDFPlayer.playFolder(6, 5);
  DBSCL12=1;
 } 
 if ((digitalRead(CAOBANG)==0)&&(demvungmien==8)&&(DBSCL13==5))
 {
  while (digitalRead(CAOBANG)==0){}
  myDFPlayer.playFolder(6, 12);
  DBSCL13=1;
 }
}
