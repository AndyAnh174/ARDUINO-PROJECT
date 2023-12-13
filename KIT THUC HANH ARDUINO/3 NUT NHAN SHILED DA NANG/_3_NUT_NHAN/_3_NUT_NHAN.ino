int LED[]={10,11,12,13};
#define S1 A1
#define S2 A2
#define S3 A3
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<4;i++)
{
  pinMode(LED[i],OUTPUT);
}
pinMode(S1,INPUT_PULLUP);
pinMode(S2,INPUT_PULLUP);
pinMode(S3,INPUT_PULLUP);
for(int i=0;i<4;i++)
{
  digitalWrite(LED[i],1);
}
}


void loop() {
 if(digitalRead(S1)==0)
 {
 do{}
 while(digitalRead(S1)==1);
 digitalWrite(10,0);
 }
 else
 {
  digitalWrite(10,1);
 }
 }


