//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once

namespace math {
    class Calculator {
    public:
        virtual double add(double a, double b) = 0;
        virtual double sub(double a, double b) = 0;
        virtual ~Calculator() = default;
    };
}