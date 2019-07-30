char serialData;
int led=13;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    serialData=Serial.read();
    Serial.print(serialData);

   if(serialData=='1'){
    digitalWrite(led,HIGH);
   }
   else if(serialData=='0'){
    digitalWrite(led,LOW);
   }
}
}
