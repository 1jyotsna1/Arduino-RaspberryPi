import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(22,GPIO.IN)

while True:
    sensor=GPIO.input(22)

    if sensor==1:
        print("I see something")
        
    elif sensor==0:
        print("I see nothing")

