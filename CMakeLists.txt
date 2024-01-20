cmake_minimum_required(VERSION 3.26)
project(Timer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Timer main.cpp src/Timer.cpp src/Timer.h)
