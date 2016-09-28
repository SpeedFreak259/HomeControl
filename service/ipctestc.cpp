#include <zmq.h>
#include "homeControl.pb.h"

int main(void){
  void *context = zmq_ctx_new();
  void *socket = zmq_socket(context. ZMQ_PAIR);

  socket.bind("tcp://*:19000");

  zmq_close(socket);
  zmq_ctx_destroy(context);
}
