#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
char auth[] = "75957b096650422f85167bc58ed1793b";
char ssid[] = "Minh Thao Bui";
char pass[] = "0913337272";
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 11 ); // TX, RX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600
#define R 2
#define L 13
ESP8266 wifi(&EspSerial);
void setup() {
 pinMode(R,OUTPUT);
 pinMode(L,OUTPUT);
 Serial.begin(9600);
 EspSerial.begin(ESP8266_BAUD);
 Blynk.begin(auth, wifi, ssid, pass);
}
void loop() {
    Blynk.run();
}

BLYNK_WRITE(V0){
  int x = param.asInt();
  digitalWrite(R,x);

}
