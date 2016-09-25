from struct import *

class ControllerData():

    def __init__(self, *packets):
        # packet must be 19 bytes
        for packet in packets:

            if self.validateChecksum(packet):
                self.determinePacketType(packet)

    def _calculateCRC(self, data):
        checksum = 0 # checksum is int type
        for ch in data[:18]:
            checksum += ord(ch)
        return checksum % 256 # ensure that the checksum does not exceed 1 byte

    def validateChecksum(self, data):
        # compare received checksum with calculated checksum
        if self._calculateCRC(data) == unpack('B', data[-1])[0]:
            return True
        else:
            # validation will fail if checksum is invalid
            # or if packet is not 19 bytes in length
            return False

    def determinePacketType(self, data):
        # use first byte of packet to determine type
        if data[0] == '\x3A':
            self.type = "A"
            self._unpackPacketA(data)
        elif data[0] == '\x3B':
            self.type = "B"
            self._unpackPacketB(data)
        else:
            # set instance type to "invalid" if packet is of an unknown type
            self.type = "invalid"

    def _unpackPacketA(self, data):
        (self.throttle, self.brakePedal, self.brakeSwitch, self.footSwitch,
        self.forwardSwitch, self.reverse, self.hallA, self.hallB, self.hallC,
        self.batteryVoltage, self.motorTemp, self.controllerTemp, self.settingDir,
        self.actualDir) = unpack('!2x5B4?3B2?3x', data)

    def _unpackPacketB(self, data):
        (self.rpm, self.phaseCurrent) = unpack('!4x2H11x', data)
