//https://github.com/jumejume1/AX-12A-servo-library
/*AX-12A  pin1: GND  --->  DC -12V
AX-12A  pin2: VDD  --->   DC +12V
AX-12A pin3: DATA --->  Tx pin of Arduino

*** Connect  the two grounds together ***
*/
#include <AX12A.h>

#define DirectionPin  (10u)
#define BaudRate    (1000000ul)
#define ID    (1u)

void setup()
{
 ax12a.begin(BaudRate, DirectionPin, &Serial);
 ax12a.setEndless(ID, ON);
 pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop()
{
    ax12a.ledStatus(ID, ON);
    Serial.println("on");
    digitalWrite(LED_BUILTIN, HIGH);
    ax12a.turn(ID, LEFT, 100);
    delay(5000);
  
    ax12a.ledStatus(ID, OFF);
    Serial.println("off");
    digitalWrite(LED_BUILTIN, LOW);
    ax12a.turn(ID, RIGHT, 500);
    delay(5000);
}
