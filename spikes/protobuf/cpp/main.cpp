#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "homeControl.pb.h"



int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    homeControl::DimmerCommand dimmerCommand;

    int level = 10;
    int channel = 20;

    dimmerCommand.set_level(level);
    dimmerCommand.set_channel(channel);
    dimmerCommand.set_message("Hello from C++!");

    //  Send reply back to client
    std::string responseMessage;

    if(dimmerCommand.SerializeToString(&responseMessage)){
        std::fstream output("hc.dat", std::ios::out | std::ios::trunc | std::ios::binary);
        dimmerCommand.SerializeToOstream(&output);

        std::fstream output2("hc.txt", std::ios::out | std::ios::trunc | std::ios::binary);
        output2 << responseMessage;

        std::cout << "File written." << std::endl;
    } else {
        std::cout << "Failed to serialize" << std::endl;
    }

    homeControl::DimmerCommand cmd2;

    cmd2.ParseFromString(responseMessage);
    if(cmd2.level() == 10){
        std::cout << "Deserialized OK." << std::endl;
    }

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
