import RPi.GPIO as gpio
import time

gpio.setwarnings(False)

gpio.setmode(gpio.BCM)	
IRsensor1=22
IRsensor2=26	
gpio.setup(22,gpio.IN)
gpio.setup(26,gpio.IN)
gpio.setup(17,gpio.OUT)
gpio.setup(27,gpio.OUT)
gpio.setup(5,gpio.OUT)
gpio.setup(6,gpio.OUT)

def init():
    gpio.setwarnings(False)
    IRsensor1=22
    IRsensor2=26
    gpio.setmode(gpio.BCM)	
	
    gpio.setup(22,gpio.IN)
    gpio.setup(26,gpio.IN)
    gpio.setup(17,gpio.OUT)
    gpio.setup(27,gpio.OUT)
    gpio.setup(5,gpio.OUT)
    gpio.setup(6,gpio.OUT)
    
def forward():
    init()    
    gpio.output(17,gpio.HIGH)
    gpio.output(27,gpio.LOW)
    gpio.output(5,gpio.HIGH)
    gpio.output(6,gpio.LOW)
    
def reverse():   
    init()
    gpio.output(17,gpio.LOW)
    gpio.output(27,gpio.HIGH)
    gpio.output(5,gpio.LOW)
    gpio.output(6,gpio.HIGH)


def left():
    init()
    gpio.output(17,gpio.LOW)
    gpio.output(27,gpio.LOW)
    gpio.output(5,gpio.LOW)
    gpio.output(6,gpio.HIGH)

def right():
    init()
    gpio.output(17,gpio.LOW)
    gpio.output(27,gpio.HIGH)
    gpio.output(5,gpio.LOW)
    gpio.output(6,gpio.LOW)

while True:
    IRsensor=gpio.input(22)
    IRsensor=gpio.input(26)
    try:
        
        if(IRsensor1==1 and IRsensor2==1):
            print('I see something')
            forward()
            
        elif(IRsensor1==0 and IRsensor2==0):
            print('I see nothing')
            reverse()
            
    except(KeyboardInterrupt):

        print("Finishing up")
        gpio.output(17,gpio.LOW)
        gpio.output(27,gpio.LOW)
        gpio.output(5,gpio.LOW)
        gpio.output(6,gpio.LOW)
        quit()

