cmake_minimum_required(VERSION 3.16.3)

project(myapp)

set (CMAKE_CXX_STANDARD 17)

add_executable(myapp main.cpp)
add_executable(prlimit prlimit.c)

