import serial
import time
arduino = serial.Serial(port='COM8', baudrate=9600, timeout = 1)
def read():
    data = arduino.readline().decode('utf-8')
    return data
def write(x):
    arduino.write(bytes(x,'utf-8'))
    time.sleep(1)

while True:
    a = input("angka? : ")
    # if a == 1:
    write(a)
    # print(read())
    # else:
    #     print('invalid')
