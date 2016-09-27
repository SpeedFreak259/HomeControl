import zmq
import time

context = zmq.Context();
socket = context.socket(zmq.PAIR);

socket.connect("tcp://127.0.0.1:19000")

poller = zmq.Poller()
poller.register(socket, zmq.POLLIN)

while True:
    socks = dict(poller.poll())

    if socket in socks and socks[socket] == zmq.POLLIN:
        msg = socket.recv_string()
        print(msg)
        socket.send_string("Send from iptestclient.py")

    time.sleep(1)
