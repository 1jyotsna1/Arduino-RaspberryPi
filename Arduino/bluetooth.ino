#include <Servo.h>
Servo myservo; 
int state;
int pos = 0; 
void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  myservo.attach(10);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 
 if (state == '0') {
  analogWrite(3, 0);
  analogWrite(5, 0); 
  analogWrite(6, 0); 
  analogWrite(9, 0);  
  Serial.println("STOP"); 
 }
 else if (state == '1') {
  analogWrite(3, 0);
  analogWrite(5, 255); 
  analogWrite(6, 255); 
  analogWrite(9, 0);
  Serial.println("FORWARD");
 } 
  else if (state == '2') {
  analogWrite(3, 255);
  analogWrite(5, 0); 
  analogWrite(6, 0); 
  analogWrite(9,255);
  Serial.println("BACKWARD");
 } 
 else if (state == '3') {
  analogWrite(3, 0);
  analogWrite(5, 0); 
  analogWrite(6, 255); 
  analogWrite(9, 0);
  Serial.println("LEFT");
 } 
 else if (state == '4') {
  analogWrite(3, 0);
  analogWrite(5, 255); 
  analogWrite(6, 0); 
  analogWrite(9,0);
  Serial.println("RIGHT");
 } 
 else if (state == '5') {
  Serial.println("GRIPPER ON");
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);             
    delay(15);                    
  } 
 } 
}}
