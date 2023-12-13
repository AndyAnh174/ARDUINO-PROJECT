#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;

void setup() 
{
 Serial.begin(9600);
 Serial.println("Initialize MPU6050");
 while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
 {
  Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
  delay(500);
 }
}

void loop()
{
  Vector normAccel = mpu.readNormalizeAccel();
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
  Serial.print(" Roll = ");
  Serial.print(roll);
  Serial.println();
  delay(50);
}
