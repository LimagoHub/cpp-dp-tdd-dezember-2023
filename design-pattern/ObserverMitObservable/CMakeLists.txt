cmake_minimum_required(VERSION 3.25)
project(ObserverMitObservable)

set(CMAKE_CXX_STANDARD 17)

add_executable(ObserverMitObservable main.cpp propertychanged/PropertyChangedListener.h propertychanged/PropertyChangedProvider.h tiere/Schwein.h tiere/Tier.h propertychanged/PropertyChangedEvent.h)
