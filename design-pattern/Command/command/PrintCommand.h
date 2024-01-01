//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include "../math/Calculator.h"

#include "AbstractCommand.h"

using Calc=math::Calculator;

namespace command {

    class PrintCommand : public AbstractCommand {
    public:
        PrintCommand()=default;
        ~PrintCommand() override = default;

        auto execute()->void override {
            Calc::getInstance()->print();
        }
    };
}