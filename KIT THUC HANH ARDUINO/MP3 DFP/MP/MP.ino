#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(8, 9); // RX, TX
DFRobotDFPlayerMini myDFPlayer; 
const int NEXT = A1;//19
const int PRE =  A2;//1
const int PLAY = A3;//19

#define encoderPinA 2
#define encoderPinB 3
#define Button 4
int encoderPos=5,chon,lastReportedPos;
boolean rotating,B_set,A_set;

boolean so=0;
void setup() {

pinMode(encoderPinA, INPUT_PULLUP); // new method of enabling pullups
pinMode(encoderPinB, INPUT_PULLUP); 
pinMode(Button, INPUT_PULLUP);
attachInterrupt(0, doEncoderA, CHANGE);
attachInterrupt(1, doEncoderB, CHANGE);
  
pinMode(NEXT,INPUT_PULLUP);
pinMode(PRE,INPUT_PULLUP);
pinMode(PLAY,INPUT_PULLUP);
Serial.begin(9600);
mySoftwareSerial.begin(9600);
if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
    
  //myDFPlayer.volume(28);  //Set volume value. From 0 to 30
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  //myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
  //myDFPlayer.play(3);
 //delay(3000);
}

void loop() {
if(digitalRead(PLAY)==0)so=!so;
if(so==1) 
{
myDFPlayer.start();
delay(100);
}
else myDFPlayer.pause(); 
delay(100);
if(digitalRead(NEXT)==0) 
{
myDFPlayer.next();
delay(100);
}
else if (digitalRead(PRE)==0)  myDFPlayer.previous();
delay(100);
Serial.println(encoderPos);

myDFPlayer.volume(encoderPos);
delay(100);
}
// Interrupt on A changing state
void doEncoderA(){
  // debounce
  if ( rotating ) delay (1);  // wait a little until the bouncing is done

  // Test transition, did things really change? 
  if( digitalRead(encoderPinA) != A_set ) {  // debounce once more
    A_set = !A_set;

    // adjust counter + if A leads B
    if ( A_set && !B_set ) 
      encoderPos += 1;
      if(encoderPos>30) encoderPos=30;
    rotating = false;  // no more debouncing until loop() hits again
  }
}

// Interrupt on B changing state, same as A above
void doEncoderB(){
  
  if ( rotating ) delay (1);
  if( digitalRead(encoderPinB) != B_set ) {
    B_set = !B_set;
    
    //  adjust counter - 1 if B leads A
    if( B_set && !A_set ) 
      encoderPos -= 1;
      if(encoderPos<0) encoderPos=0;
      rotating = false;
  }
}
