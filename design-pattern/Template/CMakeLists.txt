cmake_minimum_required(VERSION 3.25)
project(Template)

set(CMAKE_CXX_STANDARD 17)

add_executable(Template main.cpp processor/handler/FileHandler.h processor/handler/AbstractFileHandler.h processor/handler/AbstractCounter.h processor/handler/CharacterCounter.h processor/FileProcessor.h)
