cmake_minimum_required(VERSION 3.8)
project(ObjFormatReader)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp structs.h utility.h objformat_reader.cpp objformat_reader.h)
add_executable(ObjFormatReader ${SOURCE_FILES})