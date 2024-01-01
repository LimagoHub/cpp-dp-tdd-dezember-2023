//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <iostream>
#include <memory>
#include "../math/Calculator.h"

namespace clients {
    class CalculatorClient {
        std::unique_ptr<math::Calculator> calculator_;

    public:
        explicit CalculatorClient(std::unique_ptr<math::Calculator> calculator) : calculator_(std::move(calculator)) {}


        void go() {
            std::cout << calculator_->add(3,4) << std::endl;
        }
    };
}
