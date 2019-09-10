import serial
ser = serial.Serial()
ser.port='COM3'
ser.open()
ser.write(b'hello\n')
data = ser.read(5)
print(data)
ser.close()
