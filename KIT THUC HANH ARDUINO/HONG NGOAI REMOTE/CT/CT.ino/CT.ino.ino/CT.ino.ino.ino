/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 2;
int rl = 5;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(2,INPUT_PULLUP);
  pinMode(rl,OUTPUT);
  digitalWrite(2,1);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  if(results.value==0xE318261B) 
  {
    results.value=0xff;
    digitalWrite(rl,!digitalRead(rl));
  }
   //else if(results.value==0x8C22657B) 
  //{
    //digitalWrite(rl,0);
  //}
}
