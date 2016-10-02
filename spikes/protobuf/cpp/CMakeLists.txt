cmake_minimum_required(VERSION 3.3)
project(ProtobufTestProject)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp homeControl.pb.h homeControl.pb.cc)

add_executable(ProtobufTestProject ${SOURCE_FILES})
# The following line will link with libzmq.so
TARGET_LINK_LIBRARIES( ProtobufTestProject ${PROTOBUF_LIBRARIES})
