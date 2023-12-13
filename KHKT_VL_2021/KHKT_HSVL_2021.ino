#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
#define CBIEN A0
#define REMOTEA 7
#define REMOTEB 12

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
 myDFPlayer.volume(12);
 myDFPlayer.volumeUp();
 myDFPlayer.volumeDown();
 myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
 pinMode(CBIEN, INPUT_PULLUP);
 pinMode(REMOTEA, INPUT_PULLUP);
 pinMode(REMOTEB, INPUT_PULLUP);
}
void loop()
{
 if ((analogRead(A0)>140)||(digitalRead(REMOTEA)==1)||(digitalRead(REMOTEB)==1))
 {
  delay(2000);
  if (((analogRead(A0)>140)&(analogRead(A0)<250))||(digitalRead(REMOTEA)==1))
  {
   myDFPlayer.play(2);
   delay(4000);
  } 
  if (((analogRead(A0)>260)&(analogRead(A0)<=1023))||(digitalRead(REMOTEB)==1))
  {
   while(1)
   {
    myDFPlayer.play(1);
    delay(5000);
    if(analogRead(A0)<140) 
    {                              
     break;
    }  
   }
  }
 }
 else
 {
  Serial.println(analogRead(A0));
 }
}
