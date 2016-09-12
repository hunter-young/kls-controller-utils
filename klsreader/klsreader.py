import time
from pprint import pprint
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

class KLSReader(object):
    def __init__(self, serialport):
        self.connector = ControllerConnector(serialport)
        self.connector.startSerial()
        self.command = ControllerCommand()

    def getData(self):
        packet_a, packet_b = self.connector.getBytes(self.command.a, self.command.b)
        data = ControllerData(packet_a, packet_b)
        return data.__dict__

if __name__ == "__main__":
    # change to the appropriate commport when running as __main__
    serialport = '/dev/ttyUSB0'

    controller = KLSReader(serialport)
    print("Connected to motor controller")

    try:
        while 1:
            data = controller.getData()
            pprint(data.__dict__)
            time.sleep(1)

    except KeyboardInterrupt:
        print("Terminating connection")
