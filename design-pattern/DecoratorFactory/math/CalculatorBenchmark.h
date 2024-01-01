//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include "Calculator.h"

using Calc_Pointer = std::unique_ptr<math::Calculator>;

namespace math {
    class CalculatorBenchmark: public Calculator{
        Calc_Pointer calculator_;


        explicit CalculatorBenchmark(Calc_Pointer calculator)
                : calculator_(std::move(calculator)) {}

    public:
        double add(double a, double b) override {
            auto start = std::chrono::high_resolution_clock::now();
            auto result = calculator_->add(a,b);
            auto ende  = std::chrono::high_resolution_clock::now();
            std::cout << std::endl << "Zeit: " << std::chrono::duration_cast<std::chrono::nanoseconds>(ende-start).count() << " ns" << std::endl;
            return result;
        }

        double sub(double a, double b) override {
            auto start = std::chrono::high_resolution_clock::now();
            auto result = calculator_->sub(a,b);
            auto ende  = std::chrono::high_resolution_clock::now();
            std::cout << std::endl << "Zeit: " << std::chrono::duration_cast<std::chrono::nanoseconds>(ende-start).count() << " ns" << std::endl;
            return result;
        }

        ~CalculatorBenchmark() override = default;

        friend class CalculatorFactory;
    };
}