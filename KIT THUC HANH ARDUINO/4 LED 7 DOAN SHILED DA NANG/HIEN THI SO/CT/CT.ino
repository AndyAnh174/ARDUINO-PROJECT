#define LAT 4
#define CK 7
#define DA 8
const byte SEG[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
const byte LED[]={0xF1,0xF2,0xF4,0xF8};
void setup() {
  // put your setup code here, to run once:
pinMode(LAT,OUTPUT);
pinMode(CK,OUTPUT);
pinMode(DA,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
hienthi(1,0);
//delay(200);
hienthi(2,1);
//delay(200);
hienthi(3,2);
//delay(200);
hienthi(4,3);
//delay(200);
}
void hienthi(byte so, byte L)
{
  digitalWrite(LAT,0);
  shiftOut(DA,CK,MSBFIRST,SEG[so]);
  shiftOut(DA,CK,MSBFIRST,LED[L]);
  digitalWrite(LAT,1);
}


