cmake_minimum_required(VERSION 3.20)
project(UNO CXX)

add_executable(uno main.cpp uno.cpp)
target_include_directories(uno PUBLIC ../include)