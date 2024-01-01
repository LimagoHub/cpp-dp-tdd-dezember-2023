cmake_minimum_required(VERSION 3.25)
project(Command)

set(CMAKE_CXX_STANDARD 17)

add_executable(Command main.cpp command/Command.h command/AbstractCommand.h command/PrintCommand.h math/Calculator.h command/CommandFactory.h command/AddCommand.h math/CalculatorMemento.h command/ClearCommand.h command/CommandHistory.h)
