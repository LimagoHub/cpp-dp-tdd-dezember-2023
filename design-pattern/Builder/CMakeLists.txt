cmake_minimum_required(VERSION 3.25)
project(Builder)

set(CMAKE_CXX_STANDARD 17)

add_executable(Builder main.cpp builder/Person.h builder/Person.cpp)
