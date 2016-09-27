import zmq
import time

context = zmq.Context();
socket = context.socket(zmq.PAIR);

socket.connect("tcp://127.0.0.1:19000")

while True:
    msg = socket.recv()
    print(msg)
    socket.send("Send from iptestclient.py")
    time.sleep(1)