#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
char auth[] = "LHoxy6vTDL1fRfHUkHk5yQzlsFESlfGk";
char ssid[] = "Samsung 4G";
char pass[] = "01265106763";
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 11);
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
boolean a=1;
#define RL 5

void setup() 
{
 Serial.begin(9600);
 Serial.println(F("DHTxx test!"));
 delay(10);
 EspSerial.begin(ESP8266_BAUD);
 delay(10);
 Blynk.begin(auth, wifi, ssid, pass);
 dht.begin();
 pinMode(RL, OUTPUT);
 digitalWrite(RL, 0);
}

BLYNK_WRITE(V3)
{
 a = param.asInt();
}

void loop() 
{
 Blynk.run();
 if (a==0)
 {
  digitalWrite(RL, 1);
 }
 else
 {
  digitalWrite(RL, 0);
 }
}
