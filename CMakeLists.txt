cmake_minimum_required(VERSION 3.12)
project(XMLParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(XMLParser src/main.cpp src/xmlParser.cpp src/xmlParser.h)