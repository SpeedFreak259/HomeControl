import zmq
import time
import homeControl_pb2

context = zmq.Context();
socket = context.socket(zmq.PAIR);

socket.bind("tcp://*:19000")

id = 0
level = 0

while True:
    level += 1
    if level == 10:
        id += 1
        level = 0

    cmd = homeControl_pb2.DimmerCommand()
    cmd.channel = id
    cmd.level = level

    socket.send(cmd.SerializeToString())
    msg = socket.recv_string()
    print(msg)
    time.sleep(1)
