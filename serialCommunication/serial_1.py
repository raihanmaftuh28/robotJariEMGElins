import serial
import time
arduino = serial.Serial(port='COM6', baudrate=9600, timeout = 1)
def read():
    data = arduino.readline().decode('utf-8')
    return data
def write(x):
    arduino.write(bytes(x,'utf-8'))
    time.sleep(1)
def command(a):
    if a == "b":
        return('24002400240024002400')
    elif a == 't' :
        return('18001200120012001200')
    elif a == 'at':
        return('18002400240024002400')
    elif a == 'bt':
        return('24001200240024002400')
    elif a == 'ct':
        return('24002400120024002400')
    elif a == 'dt':
        return('24002400240012002400')
    elif a == 'et':
        return('24002400240024001200')
    elif a == 'ab':
        return('24001200120012001200')
    elif a == 'bb':
        return('18002400120012001200')
    elif a == 'cb':
        return('18001200240012001200')
    elif a == 'db':
        return('18001200120024001200')
    elif a == 'eb':
        return('18001200120012002400')
    else :
        return ('0')

while True:
    a = input("command? : ")
    data = command(a)
    if data == '0':
        print('Wrong Command')
    else :
        write(data)
    
