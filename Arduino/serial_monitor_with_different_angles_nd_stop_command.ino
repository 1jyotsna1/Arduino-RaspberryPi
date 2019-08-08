
#include "Arduino.h"
#include<Servo.h>
String readString, commandString;
String valueString;

int homeAngle = 90;
int curr_angle;
int certainAngle;
String serialResponse = "";
char sz[] = "Left certainangle";
char sy[] = "Right certainangle";
Servo myServo;
void setup()
{
  myServo.attach(10);
 Serial.begin(9600);
 Serial.setTimeout(5);
 myServo.write(homeAngle);
 delay(500);
 curr_angle=homeAngle;
 
}

void loop()
{
  if ( Serial.available())
  {
    serialResponse = Serial.readStringUntil('\r\n');

  
      commandString= serialResponse.substring(0, 2); //get the first four characters
     
      valueString = serialResponse.substring(3, 7); //get the next characters 
      //int length= valueString.length(); 
       
      
      
      Serial.println(commandString);
      Serial.println(valueString);
      
      certainAngle=valueString.toInt();
      
               if (certainAngle < 0 || certainAngle > 180)
                           {
                           Serial.println("Bad command");
                           }
                           
     
     
                else if(commandString == "LT" )
                           {
                         curr_angle = curr_angle - certainAngle;
                          myServo.write( curr_angle); 
                           
                           }
                else if(commandString=="RT")
                           {
                           curr_angle = curr_angle + certainAngle;
                           myServo.write( curr_angle);
                                                      
                           }
                           
                 
     }
  }
 
