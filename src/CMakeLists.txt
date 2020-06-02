cmake_minimum_required(VERSION 3.16)
project(SOLUTION)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -m64")

add_subdirectory("${PROJECT_SOURCE_DIR}/3_2_9_1" "${PROJECT_SOURCE_DIR}/src/3_2_9_1")
add_subdirectory("${PROJECT_SOURCE_DIR}/lab_3_4_signals" "${PROJECT_SOURCE_DIR}/src/lab_3_4_signals")

