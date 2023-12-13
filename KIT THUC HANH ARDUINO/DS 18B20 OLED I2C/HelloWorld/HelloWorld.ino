#include "U8glib.h"
#include <OneWire.h>
#include <DallasTemperature.h>

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);	// I2C / TWI 
// setup input buffer
#define LINE_MAX 30 
uint8_t line_buf[LINE_MAX] = "U8GLIB Console";
uint8_t line_pos = 0;

// setup a text screen to support scrolling
#define ROW_MAX 12
float t=0;

// Chân nối với Arduino
#define ONE_WIRE_BUS 2
//Thiết đặt thư viện onewire
OneWire oneWire(ONE_WIRE_BUS);
//Mình dùng thư viện DallasTemperature để đọc cho nhanh
DallasTemperature sensors(&oneWire);

uint8_t screen[ROW_MAX][LINE_MAX];
uint8_t rows, cols;
void draw(void) {
  u8g.setFont(u8g_font_fub17);
  u8g.drawStr( 5, 20, "NHIET DO");
  u8g.setPrintPos(9, 50);
  u8g.setFont(u8g_font_osb21);
  u8g.print(t);
  u8g.drawStr( 81, 50, "oC");
}
void clear_screen(void) {
  uint8_t i, j;
  for( i = 0; i < ROW_MAX; i++ )
    for( j = 0; j < LINE_MAX; j++ )
      screen[i][j] = 0;  
}
void setup(void) {
  sensors.begin();
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}
void loop(void) {
sensors.requestTemperatures();  
t=sensors.getTempCByIndex(0);
Serial.print("Nhiet do: ");
Serial.println(t); // vì 1 ic nên dùng 0
  // picture loop
 u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(50);
}

