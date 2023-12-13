#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);     // RX = pin D11, TX = pin D10 RX trước TX sau
int gt1;

void setup() 
{
 mySerial.begin(9600);
 Serial.begin(9600);
}
void loop() 

{
 gt1=100;
 mySerial.print(gt1);     //Lệnh gửi dữ liệu đi       
 Serial.println(gt1);        
 delay(1000);
 
 
}

