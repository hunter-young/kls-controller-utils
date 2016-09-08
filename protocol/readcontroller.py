# work in progress

from serial import Serial
import time

class SerialConnector():

        def __init__(self, serialport):
                self.port = serialport
                self.startSerial()
                
        def startSerial(self):
                self.connection = serial(self.serialport, 19200)

        def read(self):

                

#ser = serial.Serial(port='/dev/ttyUSB0',baudrate=19200,bytesize=EIGHTBITS,parity=PARITY_NONE,stopbits=STOPBITS_ONE,timeout=None)
ser = serial.Serial('/dev/ttyUSB0', 19200)

print("Connected to motor controller")

cmd1 = '\x3A\x00\x3A'
cmd2 = '\x3B\x00\x3B'

while 1:
	ser.write(cmd1)
	packet1 = ser.read(19)
	ser.write(cmd2)
	packet2 = ser.read(19)
	data = ControllerData(packet1, packet2)
	print data.__dict__
	time.sleep(1)
