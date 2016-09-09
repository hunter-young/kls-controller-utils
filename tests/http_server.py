from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler
from SocketServer import ThreadingMixIn
import threading
import json

jsonObj = []

class HTTPHandler(BaseHTTPRequestHandler):

    def do_GET(request):
        request.send_response(200)
        request.send_header('Content-type', 'application/json')
        request.end_headers()

        jsonStr = json.dumps(jsonObj)
        request.wfile.write(jsonStr)

class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    '''Here come dat threaded server boi...'''

if __name__ == '__main__':
    server = ThreadedHTTPServer(('localhost', 8000), HTTPHandler)
    server.serve_forever()



