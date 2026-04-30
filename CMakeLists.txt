cmake_minimum_required(VERSION 4.2)
project(Task_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task_7 sources/main.cpp
        headers/algorithm.h
        headers/brute_force.h
        sources/brute_force.cpp
        headers/divide_and_conquer.h
        sources/divide_and_conquer.cpp
        headers/dynamic_programming.h
        sources/dynamic_programming.cpp)
