//DONG CO 1
#define AT 6
#define AL 7   
//DONG CO 2 
#define BT 8
#define BL 9  
void setup() {
  // put your setup code here, to run once:
pinMode(AT,OUTPUT);
pinMode(AL,OUTPUT);
pinMode(BT,OUTPUT);
pinMode(BL,OUTPUT);
}

void loop() {
//DONG CO 1
digitalWrite(AT,1);
digitalWrite(AL,0);
//DONG CO 2
digitalWrite(BT,1);
digitalWrite(BL,0);
delay(2000);
//DONG CO 1
digitalWrite(AT,0);
digitalWrite(AL,1);
//DONG CO 2
digitalWrite(BT,0);
digitalWrite(BL,1);
delay(2000);
}
