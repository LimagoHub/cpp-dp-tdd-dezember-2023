cmake_minimum_required(VERSION 3.25)
project(ObserverAdapter)

set(CMAKE_CXX_STANDARD 17)

add_executable(ObserverAdapter main.cpp tiere/Schwein.h tiere/Tier.h)
