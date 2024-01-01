cmake_minimum_required(VERSION 3.25)
project(Visitor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Visitor main.cpp mitarbeiter/AbstractMitarbeiter.h mitarbeiter/GehaltsEmpfaenger.h mitarbeiter/LohnEmpfaenger.h firma/Firma.h mitarbeiter/visitor/MitarbeiterVisitor.h mitarbeiter/visitor/AbstractMitarbeiterVisitor.h mitarbeiter/visitor/PrintVisitor.h mitarbeiter/visitor/ResetArbeitszeitVisitor.h)
