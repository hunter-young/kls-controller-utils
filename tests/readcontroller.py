import time
import sys
import os
sys.path.insert(0, os.path.abspath('..'))

from klsreader.klsreader import KLSReader

commport = '/dev/ttyUSB0'

controller = KLSReader(commport)

print("Connected to motor controller")

while 1:
    print(controller.getData())
    time.sleep(1)
