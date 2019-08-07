import RPi.GPIO as GPIO
import sys
import Adafruit_DHT
import time
import pyttsx3

servoPIN = 17
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPIN, GPIO.OUT)

p = GPIO.PWM(servoPIN, 50) # GPIO 17 for PWM with 50Hz
p.start(2.5) # Initialization
while True:

    humidity, temperature = Adafruit_DHT.read_retry(11, 4)

    print('Temperature',temperature,'Humidity',humidity)

    if temperature>=24:
        print ('Temperature greater than 24\n')
        engine=pyttsx3.init()
        engine.say('It is way to hot')
        engine.runAndWait()
        p.ChangeDutyCycle(5)
        time.sleep(1)
    else:
        print ('Temperature under 24\n')
        engine=pyttsx3.init()
        engine.say('It is just fine')
        engine.runAndWait()
        time.sleep(1)
       
