import time
from serial import Serial
from protocol.controllerdata import *
from protocol.controllercommand import *

class ControllerConnector(object):
    def __init__(self, serialport):
        self.serialport = serialport

    def startSerial(self):
        self.connection = Serial(self.serialport, 19200, timeout=5)
        print("Connected to motor controller")

    def getBytes(self, *commands):
        ser = self.connection
        packets = []
        for command in commands:
            ser.write(command)
            packet = ser.read(19)
            packets.append(packet)
        return packets

if __name__ == "__main__":
    connector = ControllerConnector('COM1')
    connector.startSerial()
    command = ControllerCommand()

    try:
        while 1:
            data = ControllerData(connector.getBytes(command.a, command.b))
            print data.__dict__
            time.sleep(1)

    except KeyboardInterrupt:
        print("Terminating connection")
