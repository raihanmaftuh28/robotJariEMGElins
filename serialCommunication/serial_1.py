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
        return('14001200120012001200')
    elif a == 'at':
        return('16002400240024002400')
    elif a == 'bt':
        return('24001600240024002400')
    elif a == 'ct':
        return('24002400160024002400')
    elif a == 'dt':
        return('24002400240016002400')
    elif a == 'et':
        return('24002400240024001600')
    elif a == 'ab':
        return('24001600160016001600')
    elif a == 'bb':
        return('16002400160016001600')
    elif a == 'cb':
        return('16001600240016001600')
    elif a == 'db':
        return('16001600160024001600')
    elif a == 'eb':
        return('16001600160016002400')
    else :
        return ('0')

while True:
    a = input("command? : ")
    data = command(a)
    if data == '0':
        print('Wrong Command')
    else :
        write(data)
    
    # print(read())
    # else:
    #     print('invalid')
