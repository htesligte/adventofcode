cmake_minimum_required(VERSION 3.3)
project(day7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    day7-1.cpp Part.cpp Part.h Statement.cpp Statement.h)

add_executable(day7 ${SOURCE_FILES})