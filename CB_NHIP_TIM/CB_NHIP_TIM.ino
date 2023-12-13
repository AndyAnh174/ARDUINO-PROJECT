#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
MAX30105 particleSensor;
const byte RATE_SIZE = 4;
byte rates[RATE_SIZE];
byte rateSpot = 0;
long lastBeat = 0;
float beatsPerMinute;
int beatAvg, spo2;

void setup()
{
 Serial.begin(9600);
 Serial.println("Initializing...");
 if (!particleSensor.begin(Wire, I2C_SPEED_FAST))
 {
  Serial.println("MAX30105 was not found. Please check wiring/power. ");
  while (1);
 }
 Serial.println("Place your index finger on the sensor with steady pressure.");
 particleSensor.setup();
 particleSensor.setPulseAmplitudeRed(0x0A);
 particleSensor.setPulseAmplitudeGreen(0);
}
void loop()
{
 long irValue = particleSensor.getIR();
 if (checkForBeat(irValue) == true)
 {
  long delta = millis() - lastBeat;
  lastBeat = millis();
  beatsPerMinute = 60 / (delta / 1000.0);
  if (beatsPerMinute < 255 && beatsPerMinute > 20)
  {
   rates[rateSpot++] = (byte)beatsPerMinute;
   rateSpot %= RATE_SIZE;
   beatAvg = 0;
   for (byte x = 0 ; x < RATE_SIZE ; x++)
   beatAvg += rates[x];
   beatAvg /= RATE_SIZE;
   beatAvg=beatAvg+20;
  }
 }
 if ((beatAvg < 110)&&(beatAvg >= 90))
 {
  spo2=99;
 }
 if ((beatAvg < 90)&&(beatAvg >= 80))
 {
  spo2=98;
 }
 if ((beatAvg < 80)&&(beatAvg >= 75))
 {
  spo2=97;
 }
 if ((beatAvg < 75)&&(beatAvg >= 70))
 {
  spo2=96;
 }
 if ((beatAvg < 70)&&(beatAvg >= 50))
 {
  spo2=94;
 }
 if (irValue > 50000)
 {
  Serial.print("BPM=");
  Serial.print(beatAvg);
  Serial.print(", SPO2=");
  Serial.print(spo2);
  Serial.println();
 }
 if (irValue < 50000)
 {
  Serial.print("Chua nhan vung do");
  Serial.println();
  beatsPerMinute=0;
  beatAvg=0;
  spo2=0;
 }
}
