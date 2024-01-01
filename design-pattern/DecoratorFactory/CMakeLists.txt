cmake_minimum_required(VERSION 3.25)
project(DecoratorFactory)

set(CMAKE_CXX_STANDARD 17)

add_executable(DecoratorFactory main.cpp math/Calculator.h math/CalculatorImpl.h math/CalculatorFactory.h math/CalculatorLogger.h client/CalculatorClient.h math/CalculatorBenchmark.h)
