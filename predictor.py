import cv2
import numpy as np
import os
import time
import subprocess


process=subprocess.Popen('sudo echo "Hi Rins,how you doing today" | festival --tts',shell=True,stdout=subprocess.PIPE)
process.wait()
recognizer = cv2.face.LBPHFaceRecognizer_create()
recognizer.read('trainer/trainer.yml')
faceCascade = detector = cv2.CascadeClassifier('/home/pi/haarcascade_frontalface_default.xml')

font = cv2.FONT_HERSHEY_SIMPLEX

#iniciate id counter
id = 0

# names related to ids: example ==> Marcelo: id=1,  etc
names = ['None', 'sweya', 'jyotsna', 'rahul','rins'] 

# Initialize and start realtime video capture
cam = cv2.VideoCapture(0)
cam.set(3, 640) # set video widht
cam.set(4, 480) # set video height

# Define min window size to be recognized as a face
minW = 0.1*cam.get(3)
minH = 0.1*cam.get(4)

while True:

    ret, img =cam.read()
    img = cv2.flip(img, +1) # Flip vertically

    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale( 
        gray,
        scaleFactor = 1.2,
        minNeighbors = 5,
        minSize = (int(minW), int(minH)),
       )

    for(x,y,w,h) in faces:

        cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)

        id, confidence = recognizer.predict(gray[y:y+h,x:x+w])

        # Check if confidence is less them 100 ==> "0" is perfect match 
        if (confidence < 100):
            id = names[id]
            print(id)
            
            confidence = "  {0}%".format(round(100 - confidence))
            if(id=="jyotsna"):
                process=subprocess.Popen('sudo echo "Jyotsna" | festival --tts',shell=True,stdout=subprocess.PIPE)
                process.wait()
                time.sleep(2)
            elif(id=="sweya"):
                process=subprocess.Popen('sudo echo "Sweya" | festival --tts',shell=True,stdout=subprocess.PIPE)
                process.wait()
                time.sleep(2)
            elif(id=="rahul"):
                process=subprocess.Popen('sudo echo "rahul" | festival --tts',shell=True,stdout=subprocess.PIPE)
                process.wait()
                time.sleep(2)
            elif(id=="rins"):
                process=subprocess.Popen('sudo echo "rins" | festival --tts',shell=True,stdout=subprocess.PIPE)
                process.wait()
                time.sleep(2)
        else:
            id = "unknown"
            print(id)
            confidence = "  {0}%".format(round(100 - confidence))
            process=subprocess.Popen('sudo echo"unknown"| festival --tts',shell=True,stdout=subprocess.PIPE)
            process.wait()
            print(process.returncode)
            time.sleep(2)
        
        cv2.putText(img, str(id), (x+5,y-5), font, 1, (255,255,255), 2)
        cv2.putText(img, str(confidence), (x+5,y+h-5), font, 1, (255,255,0), 1)  
    
    cv2.imshow('camera',img) 

    k = cv2.waitKey(10) & 0xff=='q' # Press 'ESC' for exiting video
    if k == 27:
        break

# Do a bit of cleanup
print("\n [INFO] Exiting Program and cleanup stuff")
cam.release()
cv2.destroyAllWindows()
