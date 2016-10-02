cmake_minimum_required(VERSION 3.3)
project(ZmqProject)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

# This will file libzmq.so file from /usr/local/lib
FIND_FILE(ZMQLIB libzmq.so /usr/local/lib)
IF(NOT ZMQLIB)
    MESSAGE(SEND_ERROR "Ah.. Cannot find library libzmq.so.")
ENDIF(NOT ZMQLIB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp homeControl.pb.h homeControl.pb.cc)

add_executable(ZmqProject ${SOURCE_FILES})
# The following line will link with libzmq.so
TARGET_LINK_LIBRARIES( ZmqProject ${ZMQLIB} ${PROTOBUF_LIBRARIES})
