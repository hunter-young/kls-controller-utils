from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import threading
import json
import sys
import os
sys.path.insert(0, os.path.abspath('..'))

from klsreader.klsreader import KLSReader

serialport = 'COM4'
controller = KLSReader(serialport)

class HTTPHandler(BaseHTTPRequestHandler):

    def do_GET(request):
        request.send_response(200)
        request.send_header('Content-type', 'application/json')
        request.end_headers()

        jsonStr = json.dumps(controller.getData())
        request.wfile.write(jsonStr)

class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    '''Here come dat threaded server boi...'''

if __name__ == '__main__':
    server = ThreadedHTTPServer(('localhost', 5000), HTTPHandler)
    server.serve_forever()
