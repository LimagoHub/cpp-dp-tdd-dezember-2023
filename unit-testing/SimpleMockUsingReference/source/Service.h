//
// Created by JoachimWagner on 02.01.2024.
//

#pragma once

#include <iostream>
#include "Dependency.h"

class Service {
    Dependency &dependency;

public:
    explicit Service(Dependency &dependency) : dependency(dependency) {}
    void bar(int x) {
        int a = dependency.foo(x);
        std::cout << a << std::endl;
    }
};
