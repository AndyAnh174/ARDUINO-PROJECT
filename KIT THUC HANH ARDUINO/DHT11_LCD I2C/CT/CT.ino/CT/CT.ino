#include <Wire.h>
#include <LiquidCrystal_I2C_AvrI2C.h>
#include "DHT.h"
LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);
#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop() {

  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println(h);
  Serial.println(t);
  lcd.setCursor(0,0);
  lcd.print("NHIET DO:");
  lcd.setCursor(10,0);
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("DO AM:");
  lcd.setCursor(7,1);
  lcd.print(h);
}
