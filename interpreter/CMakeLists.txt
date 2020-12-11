cmake_minimum_required(VERSION 3.14)
project(interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(interpreter run/interpreter.cpp)