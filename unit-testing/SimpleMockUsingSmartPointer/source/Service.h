//
// Created by JoachimWagner on 02.01.2024.
//

#pragma once

#include <iostream>
#include <memory>
#include "Dependency.h"

class Service {
    using DependencyPointer = std::unique_ptr<Dependency>;


    DependencyPointer dependency;

public:
    explicit Service(DependencyPointer dependency) : dependency(std::move(dependency)) {}
    void bar(int x) {
        int a = dependency->foo(x);
        std::cout << a << std::endl;
    }
};
