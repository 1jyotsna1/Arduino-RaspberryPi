const int lineFollowSensor0 = A0;
const int lineFollowSensor1 = A1;
const int lineFollowSensor2 = A2;
const int lineFollowSensor3 = A3;
const int lineFollowSensor4 = A4;
const int leftsen = A6;
const int rightsen = A5;

String mode = "";

float Kp=40,Ki=2,Kd=4000;        // kp = 70
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;

int IN1 = 2;
int IN2 = 3;
int IN3 = 8;
int IN4 = 9;
int LFSensor[5]={0, 0, 0, 0, 0};
int leftsenr,rightsenr;
int inimotorspeed = 100;
int maxSpeed = 250;
void followLine(int l1,int l2,int r1, int r2);
void motorStop();
void readSensorValues();
void oneStep();

void setup() 
{
Serial.begin(9600);
pinMode(lineFollowSensor0,INPUT);
pinMode(lineFollowSensor1,INPUT);
pinMode(lineFollowSensor2,INPUT);
pinMode(lineFollowSensor3,INPUT);
pinMode(lineFollowSensor4,INPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(leftsen,INPUT);
pinMode(rightsen,INPUT);
pinMode(52,OUTPUT);
pinMode(53,OUTPUT);

digitalWrite(52,HIGH);
digitalWrite(53,HIGH);
}

void loop()
{
  readSensorValues();
  calculatePID();
  
  int rightSpeed = inimotorspeed - PID_value;
  int leftSpeed = inimotorspeed + PID_value;
  
  Serial.print("Right");Serial.println(rightSpeed);
  Serial.print("Left");Serial.println(leftSpeed);
  
  if(rightSpeed<0)rightSpeed = 0;// Prevent from going to zero
  if(leftSpeed<0)leftSpeed = 0;// Prevent from going to zero
  if (rightSpeed > maxSpeed ) rightSpeed = maxSpeed; // prevent the motor from going beyond max speed
  if (leftSpeed > maxSpeed ) leftSpeed = maxSpeed; // prevent the motor from going beyond max 
  
  switch(mode)
  {
    case "Follow":
    followLine(rightSpeed,0,leftSpeed,0);
    break;
    case "Stop":
    motorStop();
    break;
    case "left":
      oneStep();
      turnLeft();
      break;
    case "right":
      oneStep();
      turnRight();
      break;
    default:
    motorStop();
    break;
    
  }
}

void calculatePID()
{
    P = error;
    I = I + previous_I;
    D = error-previous_error;
    PID_value = (Kp*P) + (Ki*I) + (Kd*D);
    previous_I=I;
    previous_error=error;
//  Serial.println(PID_value);
}


void readSensorValues() {

LFSensor[0] = digitalRead(lineFollowSensor0);
LFSensor[1] = digitalRead(lineFollowSensor1);
LFSensor[2] = digitalRead(lineFollowSensor2);
LFSensor[3] = digitalRead(lineFollowSensor3);
LFSensor[4] = digitalRead (lineFollowSensor4);
leftsenr = digitalRead(leftsen);
rightsenr = digitalRead(rightsen);


if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 )) //11110
{
  error = 4;
  mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 )) //11100
{
error = 3; 
 mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 )) //11101
{
error = 2;
 mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 )) //11001
{
error = 1;
 mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) //11011
{
error = 0;
mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) //10011
{
error =- 1;
mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) //10111
{
error = -2;
mode = "Follow";
}
else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) //00111
{
error = -3;
mode = "Follow";
}
else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )) //01111
{
error = -4;
mode = "Follow";
}
else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 )||
(LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 )) 
{
  error = 5;
  mode = "Stop";
}

else if( leftsenr = 1 ) //01111
{
  mode = "left";

}
else if(rightsenr = 1) //01111
{
  mode = "right";
}
}

void followLine(int l1,int l2,int r1, int r2)
{
  analogWrite(IN1,r1);
  analogWrite(IN2,r2);
  analogWrite(IN3,l1);
  analogWrite(IN4,l2);
  delay(10);
}
void turnRight()
{
  analogWrite(IN1,100);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,100);
  delay(500);
}
void turnLeft()
{
  analogWrite(IN1,0);
  analogWrite(IN2,100);
  analogWrite(IN3,100);
  analogWrite(IN4,0);
  delay(500);
}
void motorStop()
{
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
void oneStep()
{
  analogWrite(IN1,100);
  analogWrite(IN2,0);
  analogWrite(IN3,100);
  analogWrite(IN4,0);
  delay(100);
}
