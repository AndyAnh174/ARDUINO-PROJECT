#include <Wire.h>
#include <LiquidCrystal_I2C_AvrI2C.h>
#include "DHT.h"
LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);
#define DHTPIN 3     // Digital pin connected to the DHT sensor
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#define DHTTYPE DHT22   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
char auth[] = "7e6d7457303d4a6db28672c02695c399";
char ssid[] = "Thanh Dat";
char pass[] = "01265106763";
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(10, 11); // RX, TX
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);



void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  delay(10);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  Blynk.run();
  
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
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

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  lcd.setCursor(0,0);
  lcd.print("NHIET DO:");
  lcd.setCursor(10,0);
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("DO AM:");
  lcd.setCursor(7,1);
  lcd.print(h);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);

  
}
