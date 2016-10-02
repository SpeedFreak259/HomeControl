#include <zmq.hpp>
#include <iostream>
#include <unistd.h>
#include "homeControl.pb.h"

bool s_send (zmq::socket_t & socket, const std::string & string) {

    zmq::message_t message(string.size());
    memcpy (message.data(), string.data(), string.size());

    bool rc = socket.send (message);
    return (rc);
}

int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PAIR);
    socket.bind("tcp://*:19555");

    homeControl::DimmerCommand dimmerCommand;

    int level = 0;
    int channel = 100;

    // forever loop
    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv(&request);
        std::string replyMessage = std::string(static_cast<char *>(request.data()), request.size());
//        std::string replyMessage = std::string((request.data())., request.size());
        // Print out received message
        std::cout << "Received from client: " + replyMessage << std::endl;

        //  See the gradual sending/replying from client
        sleep(1);

        level += 1;
        channel -= 1;

        dimmerCommand.set_level(level);
        dimmerCommand.set_channel(channel);

        //  Send reply back to client
        std::string responseMessage;

        if(dimmerCommand.SerializeToString(&responseMessage)){
            //s_send(socket, responseMessage);

            zmq::message_t message(responseMessage.size());
            memcpy (message.data(), responseMessage.data(), responseMessage.size());

            bool rc = socket.send (message);

            //zmq::message_t reply(responseMessage.length());
            //memcpy((void *)reply.data(), (void *)responseMessage.data(), responseMessage.length());
            //socket.send(reply);
        } else {
            std::cout << "Failed to serialize" << std::endl;
        }
//        dimmerCommand.SerializeToString(&msgToClient);

//        zmq::message_t reply(msgToClient.size());
//        memcpy((void *) reply.data(), (msgToClient.c_str()), msgToClient.size());
//        socket.send(reply);

    }

    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
