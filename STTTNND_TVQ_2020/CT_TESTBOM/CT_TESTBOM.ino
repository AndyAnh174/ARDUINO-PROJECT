#define BOM 2 //may bom
void setup() 
{
 Serial.begin(9600);
 pinMode(BOM,OUTPUT);
 digitalWrite(BOM, 0);
}

void loop() 
{
 digitalWrite(BOM,1);
 delay(7000);
 digitalWrite(BOM,0);
 delay(1000);
}
