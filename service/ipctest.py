import zmq
import time

context = zmq.Context();
socket = context.socket(zmq.PAIR);

socket.bind("tcp://*:19000")

while True:
    socket.send_string("Send from iptest.py")
    msg = socket.recv_string()
    print(msg)
    time.sleep(1)
