cmake_minimum_required(VERSION 3.5)
project(PinaHW6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp grocerystore.cpp grocerystore.h )
add_executable(Swag ${SOURCE_FILES})