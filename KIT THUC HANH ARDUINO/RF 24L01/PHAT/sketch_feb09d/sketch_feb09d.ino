#include <SPI.h>
#include "RF24.h"
#include <PS2Keyboard.h>

const int DataPin = 3;
const int IRQpin =  2;

PS2Keyboard keyboard;
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // địa chỉ để phát
RF24 radio(9,10); //thay 10 thành 53 với mega
char msg[5];
const int sensor = A0;
int value = 0;
 
void setup(){ 
  //============================================================Module NRF24
  Serial.begin(9600);
  radio.begin();                     
  radio.setAutoAck(1);               
  radio.setRetries(1,1);             
  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_MAX);      // Dung lượng tối đa
  radio.setChannel(10);               // Đặt kênh
  radio.openWritingPipe(pipe);        // mở kênh
  pinMode(sensor, INPUT);
  keyboard.begin(DataPin, IRQpin);
  Serial.println("Keyboard Test:");
}
 
void loop(){
if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      const char text[] = "ENTER";
      radio.write(&text, sizeof(text));
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      const char text[] = "ESC";
      radio.write(&text, sizeof(text));
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      const char text[] = "[Left]";
      radio.write(&text, sizeof(text));
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      const char text[] = "Right";
      radio.write(&text, sizeof(text));
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      const char text[] = "[Up]";
      radio.write(&text, sizeof(text));
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      const char text[] = "[Down]";
      radio.write(&text, sizeof(text));
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else {
      msg[0] = c;
      radio.write(&msg, sizeof(msg));
      // otherwise, just print all normal characters
      Serial.print(c);
    }
  }

  
}
