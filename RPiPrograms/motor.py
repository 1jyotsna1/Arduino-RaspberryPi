import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(17,GPIO.OUT)
GPIO.setup(18,GPIO.OUT)

print("Start motor sequence")

while True:
    try:

        GPIO.output(17,True)
        GPIO.output(18,False)
        time.sleep(3)

        GPIO.output(17,False)
        GPIO.output(18,True)
        time.sleep(3)
    except(KeyboardInterrupt):

        print("Finishing up")
        GPIO.output(17,False)
        GPIO.output(18,False)
        quit()
