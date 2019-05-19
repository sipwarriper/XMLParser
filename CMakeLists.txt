cmake_minimum_required(VERSION 3.12)
project(XMLParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(XMLParser src/main.cpp src/XMLParser.cpp src/XMLParser.h src/XHSTTPrinterModel.h src/XHSTTPrinterModel.cpp src/Model.h src/Model.cpp src/ModelEntity.cpp src/ModelEntity.h)