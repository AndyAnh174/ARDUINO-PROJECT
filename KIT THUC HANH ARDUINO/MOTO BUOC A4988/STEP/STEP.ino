// defines pins numbers
const int stepPin = 3; 
const int dirPin = 2; 
const int E = 4;  
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(E,OUTPUT);
  digitalWrite(E,0); 
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(400); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(400); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(400);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(400);
  }
  delay(1000);
}
