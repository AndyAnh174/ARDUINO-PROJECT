int LED[]={10,11,12,13};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<4;i++)
{
  pinMode(LED[i],OUTPUT);
}
}


void loop() {
  // put your main code here, to run repeatedly:
 for(int del=0;del<3;del++)
 {
  choptat();
 }
  for(int del=0;del<6;del++)
 {
  ledchay();
 }
 }
void choptat()
{
for(int i=0;i<4;i++)
{
  digitalWrite(LED[i],0);
}
delay(1000);
for(int i=0;i<4;i++)
{
  digitalWrite(LED[i],1);
}
delay(1000);
}

void ledchay()
{
 for(int i=0;i<4;i++)
{
  digitalWrite(LED[i],1);
}
delay(1000);
for(int i=0;i<4;i++)
{
  digitalWrite(LED[i],0);
  delay(200);
}
 for(int i=0;i<4;i++)
{
  digitalWrite(LED[i],1);
}
 for(int i=3;i>=0;i--)
{
  digitalWrite(LED[i],0);
  delay(200);
}
}

