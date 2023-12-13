#include <TinyGPS++.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 5);
char msg;
char call;
int CB=A0;
static const int RXPin = 4, TXPin = 3;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
float latitude,longitude;

void setup()
{
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
  ss.begin(9600);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();
}

void loop()
{
 ss.listen();
 while (ss.available() > 0)
 {
  if (gps.encode(ss.read()))
  latitude = (gps.location.lat());
  longitude = (gps.location.lng()); 
 }
 int giatri=analogRead(A0);
 if(giatri>400) 
 {
  mySerial.listen();
  MakeCall();
  delay(10000);
  HangupCall();
  SendMessage();
 } 
}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+84799896871\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Vi tri thiet bi:");// The SMS text you want to send
  mySerial.println("Vi do-Kinh do" );
  mySerial.println(String(latitude, 6));
  mySerial.println(String(longitude, 6));
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void MakeCall()
{
  mySerial.println("ATD++84799896871;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}

void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}
