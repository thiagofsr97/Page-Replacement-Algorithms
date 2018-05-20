cmake_minimum_required(VERSION 3.10)
project(Page_Replacement_Algorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Page_Replacement_Algorithms
        main.cpp
        PageReplacement.cpp
        PageReplacement.h StackList.cpp StackList.h)
