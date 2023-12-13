#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(9, 8); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
#define CBIEN1 4
#define CBIEN2 5
#define CBIEN3 6

void setup()
{
 Serial.begin(9600);
 mySoftwareSerial.begin(9600);
 Serial.println();
 Serial.println(F("DFRobot DFPlayer Mini Demo"));
 Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
 if (!myDFPlayer.begin(mySoftwareSerial)) 
 {
  Serial.println(F("Unable to begin:"));
  Serial.println(F("1.Please recheck the connection!"));
  Serial.println(F("2.Please insert the SD card!"));
  while(true);
 }
 Serial.println(F("DFPlayer Mini online."));
 myDFPlayer.setTimeOut(500);
 myDFPlayer.volume(30);
 myDFPlayer.volumeUp();
 myDFPlayer.volumeDown();
 myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
 pinMode(CBIEN1, INPUT_PULLUP);
 pinMode(CBIEN2, INPUT_PULLUP);
 pinMode(CBIEN3, INPUT_PULLUP);
}
void loop()
{
 if (digitalRead(CBIEN1)==0)
 {
  myDFPlayer.play(2);
  while (digitalRead(CBIEN1)==0){}
  myDFPlayer.play(1);
 }
 if (digitalRead(CBIEN2)==0)
 {
  myDFPlayer.play(2);
  while (digitalRead(CBIEN2)==0){}
  myDFPlayer.play(1);
 }
 if (digitalRead(CBIEN3)==0)
 {
  myDFPlayer.play(2);
  while (digitalRead(CBIEN3)==0){}
  myDFPlayer.play(1);
 }
}
