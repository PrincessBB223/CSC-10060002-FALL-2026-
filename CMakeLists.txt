cmake_minimum_required(VERSION 4.3)
project(CS1)

set(CMAKE_CXX_STANDARD 20)

# The main assignment/entry point
add_executable(CS1 main.cpp)

# Create a separate target for Week 3
add_executable(Week3 cmake-build-debug/Week3.cpp)

# Create a separate target for Assignment 4
add_executable(Assignment4 cmake-build-debug/Assignment4.cpp
        week4C++PP.cpp)

# Create a separate target for Week 4 C++
add_executable(Week4C week4C++.cpp)

# Create a separate target for Week 4 C++ PP
add_executable(week4_cpp week4C++PP.cpp)

# Create a separate target for Week 5 C++
add_executable(week5C++ "week4 /week5C++.cpp")

# Create a separate target for Week6
add_executable(week6c++ "week4 /week6.cpp")
add_executable(October-13-lecture "week4 /October 13th .cpp")
