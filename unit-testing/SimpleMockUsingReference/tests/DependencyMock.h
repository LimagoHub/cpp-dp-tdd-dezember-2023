//
// Created by JoachimWagner on 02.01.2024.
//

#pragma once

#include "gmock/gmock.h"
#include "../source/Dependency.h"


class DependencyMock: public Dependency{
public:
    MOCK_METHOD(int, foo, (int x), (const override));
};
