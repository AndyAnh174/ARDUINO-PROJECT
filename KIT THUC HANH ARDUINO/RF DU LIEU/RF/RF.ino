/*  Example of temperature update via UART
     Cytron Arduino examples
     Tutorial: Wireless UART with Arduino and 433MHz or 434MHz module
     URL: http://tutorial.cytron.com.my/2014/05/15/wireless-uart-with-arduino-and-433mhz-or-434mhz-module/
     This example code uses software serial to receive and trasmit data from/to 433MHz 1KM wireless module, it can be used for 434Mhz 100m wireless module too
     The reason to use software serial is due to 1K series resistor on RX and TX pin of 433MHz (1KM) module and also hardware UART pin on Arduino.
     These resistors will cause the transmit to Arduino to fail, receiving data from Arduino and transmit out wirelessly is not issue.
     Of course, this example code can be used on 434MHz 100 meters wireless module. 
     433MHz (1KM) wireless UART module: http://www.cytron.com.my/viewProduct.php?pcode=RF-UART-433-1KM&name=433MHz%20RF%20(UART)%20Transceiver%20Module-1km
     434MHz (100M) wireless UART module: http://www.cytron.com.my/viewProduct.php?pcode=RF-UART-434-100M&name=434MHz%20RF%20Transceiver%20Module%20(UART)-100m
     http://www.cytron.com.my
*/

#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"
#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
float temperature = 0.0;  //varaible to store temperature value
int LED = 13;  //LED on Arduino board
byte rx_data = 0; //variable to store receive data

SoftwareSerial mySerial(10, 11); // RX = pin D2, TX = pin D3

// Chân nối với Arduino
#define ONE_WIRE_BUS 2
//Thiết đặt thư viện onewire
OneWire oneWire(ONE_WIRE_BUS);
//Mình dùng thư viện DallasTemperature để đọc cho nhanh
DallasTemperature sensors(&oneWire);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  pinMode(LED, OUTPUT);  
  mySerial.begin(9600); //initialize software UART for 9600bps 
  sensors.begin();
  Serial.begin(9600);
  dht.begin();
}

void loop(){  
   float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  sensors.requestTemperatures();  
  temperature = sensors.getTempCByIndex(0);
  //mySerial.print("Temperature = " );    //print string on Serial monitor                     
  mySerial.print(temperature);
  mySerial.print(' '); 
  mySerial.print(t);
  mySerial.print(' '); 
  mySerial.print(h);
  //mySerial.print(' ');  
  //mySerial.write('*');  //degree symbol 
  //mySerial.println('C');  

  Serial.print("Temperature = " );    //print string on Serial monitor                     
  Serial.print(temperature);
  Serial.print(' ');  
  Serial.write('*');  //degree symbol 
  Serial.println('C');
  Serial.print(' ');  
  Serial.print("Nd DHT = " ); 
  Serial.print(t);   
  Serial.print(' ');  
  Serial.print("Da DHT = " ); 
  Serial.print(h);   
  delay(200);   
  
  if(mySerial.available()) // check if UART receive data
  {
    rx_data = mySerial.read();  //store data received
    if(rx_data == 'a')  //if the character received is 'a'
    digitalWrite(LED, HIGH);  
    else if ( rx_data == 'A') //if the character received is 'A'
    digitalWrite(LED, LOW); 
  }
}
