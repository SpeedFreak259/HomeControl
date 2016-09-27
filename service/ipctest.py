import zmq
import time

context = zmq.Context();
socket = context.socket(zmq.PAIR);

socket.bind("tcp://*:19000")

while True:
    socket.send("Send from iptest.py")
    msg = socket.recv()
    print(msg)
    time.sleep(1)