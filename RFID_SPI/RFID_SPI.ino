/*
Kết nối với Arduino Nano(Uno) hoặc Arduino Mega 2560(Pro):
 * Signal       Pin                    Pin               Pin
                Arduino Nano(Uno)      Arduino Mega      MFRC522 board
 ---------------------------------------------------------------------
 * Reset        9                      5                 RST
 * SPI SS       10                     53                SDA
 * SPI MOSI     11                     51                MOSI
 * SPI MISO     12                     50                MISO
 * SPI SCK      13                     52                SCK
*/
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN  10
#define RST_PIN 9
#define LED     2   // Led
#define KHOA    5   // Relay
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(LED, OUTPUT);
  pinMode(KHOA, OUTPUT);
  digitalWrite(KHOA, LOW);
  digitalWrite(LED, 1);
  Serial.println("Dua the vao...");
  Serial.println();
}
void loop()
{
 if ( ! mfrc522.PICC_IsNewCardPresent())
 {
  return;
 }
 if ( ! mfrc522.PICC_ReadCardSerial())
 {
  return;
 }
 Serial.print("UID tag :");
 String content = "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++)
 {
  Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
  Serial.print(mfrc522.uid.uidByte[i], HEX);
  content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
  content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message: ");
 content.toUpperCase();
 if (content.substring(1) == "F3 0B 1F 05" )
 {
  Serial.println("DUNG THE");
  Serial.println();
  digitalWrite(LED, 0);
  digitalWrite(KHOA, 1);
  delay(2000);                 
  digitalWrite(KHOA, 0);
  digitalWrite(LED, 1);
 }
 else
 {
  Serial.println("SAI THE");
  Serial.println();
 }
}
