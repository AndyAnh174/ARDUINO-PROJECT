//NJarpa
//Arduino Data Logger with 2 DS18B20 and sample rate control(every 1 min)
//You must have a dataloger shield(RTC and SD card) mounted
// DS18B20 Pinout (Wires)
//Black   = Ground
//Blue    = Signal (Pin 2):  (Normal power mode with 3.3K to 4.7K resistor to +5 or 3.3 )
//Red     = +5 or +3.3 V

#include <Wire.h>                //Libraries we need
#include "RTClib.h"
#include <OneWire.h>           
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>



#define ONE_WIRE_BUS_PIN 2              // The pin that we are using for sensors

OneWire oneWire(ONE_WIRE_BUS_PIN);     // Setup oneWire
DallasTemperature sensors(&oneWire);   //  oneWire to Dallas Temperature.
RTC_DS1307 RTC;                        // define the Real Time Clock object

const int chipSelect = 10;              //CS pin of your data logger shield.Maybe not yours!!
File Logfile;                          //Name of the file

void setup()
{
  //pinMode(10 , OUTPUT);           //For some data logger shields.Uncomment if you need
Serial.begin(9600);  
SD.begin(chipSelect);            //Initialize the libraries
Wire.begin();
RTC.begin();
sensors.begin();    
  
 
Logfile=SD.open("Logfile.csv",FILE_WRITE);                //Open and write once, just for headers
Logfile.println(" Ngày/tháng        Nhiệt độ");    //Print headers(not saved yet)
Logfile.close();                                        //Print saved

}
void loop()
{

DateTime now = RTC.now();        // Clock call


if(now.second()==00){          //Sample every minute

 Logfile=SD.open("Logfile.csv",FILE_WRITE);       

 now = RTC.now();                 // Print date and time

Logfile.print(now.year(), DEC);
Logfile.print("/");
Logfile.print(now.month(), DEC);
Logfile.print("/");
Logfile.print(now.day(), DEC);
Logfile.print(" ");
Logfile.print(now.hour(), DEC);
Logfile.print(":");
Logfile.print(now.minute(), DEC);
Logfile.print(":");
Logfile.print(now.second(), DEC);
Logfile.print("    ");              //Space beween date/time and temp1
Logfile.close();                  //Save date and time

   
  sensors.requestTemperatures(); // Command all devices on bus to read temperature
  Logfile=SD.open("Logfile.csv",FILE_WRITE); //Print temp
  //If you want fahrenheit, use(sensors.getTempFByIndex(X)
 Logfile.print(sensors.getTempCByIndex(0));
 Logfile.print(" ");
 Logfile.println();
 Logfile.close();
 Serial.print(now.hour(), DEC);
 Serial.print(":");
 Serial.print(now.minute(), DEC);
 Serial.print(":");
 Serial.print(now.second(), DEC);
 Serial.print("   ");
 Serial.println(sensors.getTempCByIndex(0));
}

delay(1000);                        //One data per second
}

