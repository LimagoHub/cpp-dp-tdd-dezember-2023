//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <iostream>
#include <memory>
#include "Calculator.h"

using Calc_Pointer = std::unique_ptr<math::Calculator>;



namespace math {
    class CalculatorLogger: public Calculator{
        Calc_Pointer calculator_;


        explicit CalculatorLogger(Calc_Pointer calculator)
            : calculator_(std::move(calculator)) {}

    public:
        double add(double a, double b) override {
            std::cout << "Add wird aufgerufen" << std::endl;
            return calculator_->add(a,b);
        }

        double sub(double a, double b) override {
            std::cout << "Sub wird aufgerufen" << std::endl;
            return calculator_->sub(a,b);
        }

        ~CalculatorLogger() override = default;

        friend class CalculatorFactory;
    };
}