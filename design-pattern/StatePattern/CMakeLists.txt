cmake_minimum_required(VERSION 3.25)
project(StatePattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        StatePattern
        main.cpp
        trafficlight/states/TrafficLightState.h trafficlight/states/AbstractTrafficLightState.h trafficlight/TrafficLight.cpp trafficlight/TrafficLight.h trafficlight/states/RedState.h trafficlight/states/GreenState.h)
