import serial
import tkinter

arduinoData=serial.Serial('COM3',9600)

def led_on():
    arduinoData.write(b'1')

def led_off():
    arduinoData.write(b'0')

led_window=tkinter.Tk()
button=tkinter.Button

btn1=button(led_window,text="ON",command=led_on)
btn2=button(led_window,text="OFF",command=led_off)

btn1.grid(row=0,column=1)
btn2.grid(row=1,column=1)
led_window.mainloop()

'''
t=0
while(t<2000):
    if(t%100==0):
        print(t)
    t+=1

led_on()

print("Done")
'''

    
