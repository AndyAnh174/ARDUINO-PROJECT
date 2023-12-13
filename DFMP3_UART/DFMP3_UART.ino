#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(5, 6);
DFRobotDFPlayerMini myDFPlayer; 

void setup() 
{
 Serial.begin(9600);
 mySoftwareSerial.begin(9600);
 if (!myDFPlayer.begin(mySoftwareSerial)) 
 {
  Serial.println(F("Unable to begin:"));
  Serial.println(F("1.Please recheck the connection!"));
  Serial.println(F("2.Please insert the SD card!"));
  while(true);
 }
 Serial.println(F("DFPlayer Mini online."));    
 myDFPlayer.volume(20);
 myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}

void loop() 
{
 myDFPlayer.play(1);
 delay(20000);
 
}
