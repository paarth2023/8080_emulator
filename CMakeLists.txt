cmake_minimum_required(VERSION 3.20)

project(emulator8080 C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(emulator8080
cpu/main.cpp
cpu/instructions.cpp)
