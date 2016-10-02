import sys
import zmq
import homeControl_pb2

context = zmq.Context()
socket = context.socket(zmq.PAIR)
port = "19555"
socket.connect ("tcp://localhost:%s" % port)

for i in range (1,10):
    socket.send_string ("saying hello from python")
    message = socket.recv()
   
    print(sys.getsizeof(message))

    dimmerCommand = homeControl_pb2.DimmerCommand()
    dimmerCommand.ParseFromString(message)

    print("Received a Dimmer Command from server")
    print("  Channel : %s    Level : %s", dimmerCommand.channel, dimmerCommand.level)
