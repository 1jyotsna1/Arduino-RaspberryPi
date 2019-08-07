#include <SimpleDHT.h>
#include<Servo.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
Servo myservo;
SimpleDHT11 dht11(pinDHT11);
int pos=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  // DHT11 sampling rate is 1HZ.
  delay(1500);

  //For motor control
  if(temperature<=25) {
  for(pos=0;pos<=180;pos+=1) {
  myservo.write(pos);
  delay(15);
 }
  }
  else {
 for(pos=180;pos>=0;pos+=1) {
 myservo.write(pos);
 delay(15);
}
delay(1000);
}
}
