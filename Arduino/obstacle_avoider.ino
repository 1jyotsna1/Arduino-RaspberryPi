int trigPin = 9;      // trig pin of HC-SR04
int echoPin = 9;     // Echo pin of HC-SR04

int revleft3 = 3;       //REVerse motion of Left motor
int fwdleft5 = 5;       //ForWarD motion of Left motor
int revright6 = 6;      //REVerse motion of Right motor
int fwdright9 = 9;      //ForWarD motion of Right motor

long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(revleft3, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright9, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  Serial.println(duration);
  distance = duration / 582;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 19)            
  {
    digitalWrite(fwdright9, HIGH);                    // move forward
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, HIGH);                                
    digitalWrite(revleft3, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdright9, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft3, LOW);
    delay(500);
    digitalWrite(fwdright9, LOW);      //movebackword         
    digitalWrite(revright6, HIGH);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft3, HIGH);
    delay(500);
    digitalWrite(fwdright9, LOW);  //Stop                
    digitalWrite(revright6, LOW);
    digitalWrite(fwdleft5, LOW);                                
    digitalWrite(revleft3, LOW);  
    delay(100);  
    digitalWrite(fwdright9, HIGH);       
    digitalWrite(revright6, LOW);   
    digitalWrite(revleft3, LOW);                                 
    digitalWrite(fwdleft5, LOW);  
    delay(500);
  }

}
