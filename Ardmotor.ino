
void setup()
{
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
}
void loop()
{
int sensor1value=digitalRead(A0);
int sensor2value=digitalRead(A1);

if(sensor1value==HIGH && sensor2value==HIGH)
{
analogWrite(3,100);
analogWrite(5,0);
analogWrite(6,100);
analogWrite(9,0); 
}

else if(sensor1value==LOW && sensor2value==LOW)
{
analogWrite(3,0);
analogWrite(5,100);
analogWrite(6,0);
analogWrite(9,100); 

delay(2);
analogWrite(3,0);
analogWrite(5,0);
analogWrite(6,0);
analogWrite(9,100); 
delay(2);

}

else if(sensor1value==LOW && sensor2value==HIGH)
{
analogWrite(3,0);
analogWrite(5,100);
analogWrite(6,0);
analogWrite(9,100);

delay(2);
analogWrite(3,0);
analogWrite(5,0);
analogWrite(6,0);
analogWrite(9,100); 
delay(2);
}

else if(sensor1value==HIGH && sensor2value==LOW)
{
analogWrite(3,0);
analogWrite(5,100);
analogWrite(6,0);
analogWrite(9,100); 

delay(2);
analogWrite(3,0);
analogWrite(5,0);
analogWrite(6,0);
analogWrite(9,100);
delay(2);

}
}

