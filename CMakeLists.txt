cmake_minimum_required(VERSION 3.8)
project(ObjFormatReader)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCE_FILES  structs.h utility.h objformat_reader.cpp objformat_reader.h)
set(TEST_FILES test/utility_test.cpp)

add_executable(ObjFormatReader main.cpp ${SOURCE_FILES})
add_executable(runtest ${SOURCE_FILES} ${TEST_FILES})
include_directories("${BASEPATH}/Catch2/include/")


find_library(BENCHMARK_LIB NAMES lbenchmark)
IF (BENCHMARK_LIB)
    message("GOOGLE BENCHMARK library found, build ")
    set(BENCHMARK_FILES benchmarks/impl_benchmarks.cpp benchmarks/objformat_benchmark.cpp)
    add_executable(runbenchmark ${SOURCE_FILES} ${BENCHMARK_FILES})
    include_directories("${BASEPATH}/benchmark-master/include/")
    target_link_libraries(runbenchmark -lbenchmark)
ELSE()
    message("GOOGLE BENCHMARK library not found")
ENDIF()
