cmake_minimum_required(VERSION 3.8)
project(ObjFormatReader)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES  structs.h utility.h objformat_reader.cpp objformat_reader.h)
set(TEST_FILES test/main.cpp test/utility_test.cpp)

add_executable(ObjFormatReader main.cpp ${SOURCE_FILES})
add_executable(runtest ${SOURCE_FILES} ${TEST_FILES})
include_directories("${BASEPATH}/Catch2/include/")