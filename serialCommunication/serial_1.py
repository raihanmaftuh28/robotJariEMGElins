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
    if a == "buka":
        return('24002400240024002400')
    elif a == 'tutup' :
        return('16000800060005500600')
    elif a == 'jempolBuka':
        return('24000000000000000000')
    elif a == 'telunjukBuka':
        return('00002200000000000000')
    elif a == 'tengahBuka':
        return('00000000220000000000')
    elif a == 'manisBuka':
        return('00000000000019000000')
    elif a == 'kelingkingBuka':
        return('00000000000000001800')
    elif a == 'jempolTutup':
        return('16000000000000000000')
    elif a == 'telunjukTutup':
        return('00000800000000000000')
    elif a == 'tengahTutup':
        return('00000000060000000000')
    elif a == 'manisTutup':
        return('00000000000005500000')
    elif a == 'jempolTutup':
        return('00000000000000000600')
    else :
        return ('0')

while True:
    a = input("command? : ")
    data = command(a)
    if a == '0':
        print('Wrong Command')
    else :
        write(data)
    
    # print(read())
    # else:
    #     print('invalid')
