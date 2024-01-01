cmake_minimum_required(VERSION 3.25)
project(CompositeWithCustomIterator)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompositeWithCustomIterator main.cpp src/composite/abstract_node.h src/composite/leaf.h src/composite/node.h)
