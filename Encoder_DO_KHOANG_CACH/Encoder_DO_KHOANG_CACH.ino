int pinA = 26;
int pinB = 30;
float encoderPosCount = 0;
int pinALast;
int aVal;
boolean bCW;
float distance =0;
float tinhcm = 0;
const float pi = 3.14;
const float D = 8.5;


void setup() {
 Serial.begin(9600);

}

void loop()  {
aVal = digitalRead(pinA);
  if (aVal != pinALast){
    if (digitalRead(pinB) != aVal){
      encoderPosCount ++;
      bCW = true; }
      else 
      {
        bCW = false;
        encoderPosCount--;
     }
     distance = (encoderPosCount /40) ;
    Serial.println(distance);
    tinhcm = (D*pi)*distance ;
    Serial.println(tinhcm);
    delay(300);
    pinALast = aVal;
  }
}
