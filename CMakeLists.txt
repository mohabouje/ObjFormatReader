cmake_minimum_required(VERSION 3.8)
project(ObjFormatReader)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp structs.h)
add_executable(ObjFormatReader ${SOURCE_FILES})