//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include "Calculator.h"

namespace math {
    class CalculatorImpl: public Calculator{

        CalculatorImpl() = default;

    public:
        double add(double a, double b) override {
            return a + b;
        }

        double sub(double a, double b) override {
            return a - b;
        }

        ~CalculatorImpl() override = default;

        friend class CalculatorFactory;
    };
}