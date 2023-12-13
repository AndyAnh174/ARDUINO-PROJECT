#include<Wire.h> 
#include <SoftwareSerial.h>
#include <TinyGPS.h>
TinyGPS gps;
SoftwareSerial ss(4, 3);       //CHÂN TX NỐI VỚI CHÂN 4, CHÂN RX NỐI VỚI CHÂN 3
SoftwareSerial SIM900(11, 12); //CHÂN TX NỐI VỚI CHÂN 11, CHÂN RX NỐI VỚI CHÂN 12
String textSMS=" "; //Nội dung gửi
float flat, flon, A, B;
int nutnhan = 5;
#define coi 2
void setup()
{
  Serial.begin(9600);
  SIM900.begin(9600);
  ss.begin(9600);
  Serial.print("Simple TinyGPS library v. "); 
  Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
  pinMode(nutnhan, INPUT_PULLUP);
  digitalWrite(nutnhan,1);
  pinMode(coi, OUTPUT);
  digitalWrite(coi, 1);
}

void loop()
{ 
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
   while (ss.available())
   {
    char c = ss.read();
    if (gps.encode(c))
     newData = true;
   }
  }
  if (newData)
  {
   unsigned long age;
   gps.f_get_position(&flat, &flon, &age);
   //Serial.print("LAT= ");
   //Serial.println(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
   //Serial.print("LON= ");
   //Serial.println(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
  }

 if (digitalRead(nutnhan)==0){
 while (digitalRead(nutnhan)==0){}
 delay(500);
 digitalWrite(coi, 0);
 delay(200);
 digitalWrite(coi, 1);
 Serial.print("LAT= ");
 Serial.println(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
 Serial.print("LON= ");
 Serial.println(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
 goidien();
 sendSMS(textSMS);
 delay(1000);
 digitalWrite(coi, 0);
 delay(500);
 digitalWrite(coi, 1);
 } 
}

void sendSMS(String message)
{
 SIM900.println("AT+CMGF=1");
 delay(1000);
 SIM900.println("AT+CMGS=\"+84928621023\"\r"); //SDT
 delay(1000);
 SIM900.println(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
 SIM900.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
 SIM900.println((char)26);
 delay(1000);
}

void goidien()
{
  SIM900.println("ATD+84928621023;");  //SDT
  delay(10000);
}
