#include "SPI.h"
#include "MFRC522.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void setup() 
{
 Serial.begin(9600);
 SPI.begin();
 rfid.PCD_Init();
 pinMode(3, OUTPUT);
 digitalWrite(3, 1);
 Serial.println("Hay cham the ...");
}

void loop() 
{
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
  Serial.print("Nhan phim the: ");
  Serial.println(strID);
  delay(500);
  if (strID.indexOf("C3:4F:A3:16") >= 0) 
  {
   digitalWrite(3, 0);
   delay(1000);
   digitalWrite(3, 1);
  }
}
