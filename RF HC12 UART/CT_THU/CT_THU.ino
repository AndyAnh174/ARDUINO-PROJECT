#include <SoftwareSerial.h>
int rx_data1;
char rx_data;
String storedData = "";
String storedData1 = "";
SoftwareSerial mySerial(11, 10);     // RX = pin D11, TX = pin D10 RX trước TX sau

void setup ()
{
 mySerial.begin(9600);
 Serial.begin(9600);
}
void loop()
{
 if(mySerial.available())
 {
  while(mySerial.available())  
  {
   rx_data = mySerial.read();       //Dữ liệu sẽ nhận bằng dạng kí tự
   storedData += rx_data;           //Các kí tự sẽ được ghép thành một chuỗi(xâu)
  }
 }
 if(storedData.length() >0)  
 {
  storedData1 = storedData;
  storedData="";                    //Trả chuỗi(xâu) ban đầu về chuỗi(xâu) trắng(không nội dung)
  rx_data1=storedData1.toInt();     //Chuyển từ kiểu chuỗi(xâu) sang kiểu số nguyên
  Serial.println(rx_data1);
  delay(500);
 }
}


