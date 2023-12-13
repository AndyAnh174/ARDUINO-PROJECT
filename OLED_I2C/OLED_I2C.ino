#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);	// I2C / TWI 
#define LINE_MAX 30 
uint8_t line_buf[LINE_MAX] = "U8GLIB Console";
#define ROW_MAX 12
uint8_t screen[ROW_MAX][LINE_MAX];

void clear_screen(void) 
{
 uint8_t i, j;
 for( i = 0; i < ROW_MAX; i++ )
 for( j = 0; j < LINE_MAX; j++ )
 screen[i][j] = 0;  
}

void draw1(void) 
{
 u8g.setFont(u8g_font_fur25);
 u8g.drawStr( 0, 30, "500mL");
}

void draw2(void) 
{
 u8g.setFont(u8g_font_fur25);
 u8g.drawStr( 0, 30, "600mL");
}

void setup(void) 
{
  Serial.begin(9600);
 if ( u8g.getMode() == U8G_MODE_R3G3B2 ) 
 {
  u8g.setColorIndex(255);
 }
 else 
 if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) 
 {
  u8g.setColorIndex(3);  
 }
 else 
 if ( u8g.getMode() == U8G_MODE_BW ) 
 {
  u8g.setColorIndex(1);  
 }
 else 
 if ( u8g.getMode() == U8G_MODE_HICOLOR ) 
 {
  u8g.setHiColorByRGB(255,255,255);
 }
 clear_screen();
}

void loop(void) 
{
 u8g.firstPage(); 
 draw1();
 Serial.print("ok"); 
 draw2();
}
