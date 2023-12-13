#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
int s1=0;
void setup() 
{
  Serial1.begin(9600);
  Serial.begin(9600);
  while (! Serial) 
  {
   delay(1);
  }
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) 
  {
   Serial.println(F("Failed to boot VL53L0X"));
   while(1);
  }
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}

void loop() 
{
 VL53L0X_RangingMeasurementData_t measure;
 lox.rangingTest(&measure, false);
 Serial.println(measure.RangeMilliMeter);
 s1=measure.RangeMilliMeter;
 Serial1.print(s1);
 delay(1000);
}

