import pyttsx3

engine = pyttsx3.init()

engine.setProperty('rate', 150)    
engine.setProperty('volume', 0.1) 

engine.say("You've got mail!")
engine.say("You can queue up multiple items")

engine.runAndWait()
