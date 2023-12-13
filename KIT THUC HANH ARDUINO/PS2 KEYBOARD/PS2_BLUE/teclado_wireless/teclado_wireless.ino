#include <PS2Keyboard.h>
#include <SoftwareSerial.h>  //Usaremos el puerto serial personalizado
char rec;
SoftwareSerial blue(10,11); //Rx,Tx

const int PinDatos = 3;  // Verde
const int PinReloj =  2;  // Blanco

PS2Keyboard teclado;

void setup() 

{

  delay(1000);

  teclado.begin(PinDatos, PinReloj);

  blue.begin(9600);
 Serial.begin(9600);
}

void loop() 
{
  // Si el teclado está disponible
  if (teclado.available()) {
    
    // Lee la tecla presionada
    char c = teclado.read();
    
    // Revisa algunas teclas especiales
    if (c == PS2_ENTER) {
      blue.println("ent");
      Serial.println("ent");
    } else if (c == PS2_TAB) {
      blue.println("tab");
      Serial.println("tab");
    } else if (c == PS2_ESC) {
      blue.println("esc");
      Serial.println("esc");
    } else if (c == PS2_BACKSPACE) {
      blue.println("bsp");
      Serial.println("bsp");
    } else if (c == PS2_PAGEDOWN) {
      blue.println("pgd");
      Serial.println("pgd");
    } else if (c == PS2_PAGEUP) {
      blue.println("pgu");
      Serial.println("pgu");
    } else if (c == PS2_LEFTARROW) {
      blue.println("lft");
      Serial.println("lft");
    } else if (c == PS2_RIGHTARROW) {
      blue.println("rgt");
      Serial.println("rgt");
    } else if (c == PS2_UPARROW) {
      blue.println("upk]");
      Serial.println("upk]");
    } else if (c == PS2_DOWNARROW) {
      blue.println("dwn");
      Serial.println("dwn");
    } else if (c == PS2_DELETE) {
      blue.println("del");
      Serial.println("del");
    } else {
      
      // Si no, imprime los caracteres normales
     
      blue.println(c);
      Serial.println(c);
      
    }
  }
}

