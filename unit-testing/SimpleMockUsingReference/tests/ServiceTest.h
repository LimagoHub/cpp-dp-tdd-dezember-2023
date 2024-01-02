//
// Created by JoachimWagner on 02.01.2024.
//

#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DependencyMock.h"
#include "../source/Service.h"

using namespace testing;

class ServiceTest : public Test{
protected:
    DependencyMock dependencyMock;
    Service objectUnderTest{dependencyMock};
};
