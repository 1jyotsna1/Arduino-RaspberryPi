#include<DHT.h>
#include<Servo.h>

#define DHTTYPE DHT11
Servo myservo;
int pinDHT11=3;
DHT dht(pinDHT11, DHTTYPE);
int pos=0;

void setup() {
 myservo.attach(5);
 Serial.begin(9600);
}

void loop() {
float temperature=dht.readTemperature();
Serial.print((int)temperature);
Serial.print("C");
float humidity=dht.readHumidity();
Serial.print((int)humidity);
Serial.print("%");

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
