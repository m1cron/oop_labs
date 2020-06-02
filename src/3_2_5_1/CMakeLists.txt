cmake_minimum_required(VERSION 3.16)
project(3_2_5_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2 -m64 -Wno-deprecated-register")

file(GLOB CPP "*.cpp" C "*.c")

add_executable(${PROJECT_NAME} ${CPP} ${C})