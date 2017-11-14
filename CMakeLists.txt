cmake_minimum_required(VERSION 2.4)
project(ObjFormatReader)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -march=native -m64 -flto")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCE_FILES  structs.h utility.h objformat_reader.cpp objformat_reader.h)
set(TEST_FILES test/utility_test.cpp test/objformat_test.cpp)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(objformatreader main.cpp ${SOURCE_FILES})
add_executable(runtest ${SOURCE_FILES} ${TEST_FILES})
include_directories("${BASEPATH}/Catch2/include/")


find_library(BENCHMARK_LIB NAMES lbenchmark)
IF (BENCHMARK_LIB)
    message("GOOGLE BENCHMARK library found, build ")
    set(BENCHMARK_FILES benchmarks/do_benchmarks.cpp)
    add_executable(runbenchmark ${SOURCE_FILES} ${BENCHMARK_FILES})
    include_directories("${BASEPATH}/benchmark-master/include/")
    target_link_libraries(runbenchmark -lbenchmark)
ELSE()
    message("GOOGLE BENCHMARK library not found")
ENDIF()
