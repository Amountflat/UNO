cmake_minimum_required(VERSION 3.20)
project(TEMPLETE CXX)

add_executable(tem main.cpp)
target_include_directories(tem PUBLIC ../include)