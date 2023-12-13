#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 11);
char call;

void setup()
{
 mySerial.begin(9600); 
 Serial.begin(9600);
 Serial.println("GSM SIM900A BEGIN");
 delay(100);
}

void loop()
{  
 //Calling
 mySerial.println("ATD++84799896871;"); //Phone number
 Serial.println("Calling  ");
 delay(10000);
}
