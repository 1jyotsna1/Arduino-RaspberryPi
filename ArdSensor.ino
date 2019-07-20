int sensor = A0;
void setup()

{
   

 
  pinMode(sensor,INPUT);
 
  Serial.begin(9600);

 
}

void loop()
{


int sensor_value = analogRead(sensor);


  Serial.println(sensor_value);

}
