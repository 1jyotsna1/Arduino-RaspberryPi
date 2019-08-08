import serial
ser=serial.Serial('COM6',9600)
while 1:
    while(ser.inWaiting()>0):
        data=ser.read().decode().strip()
        print(data)
