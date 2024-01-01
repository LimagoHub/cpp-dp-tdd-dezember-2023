//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once


#include "../math/Calculator.h"

#include "AbstractCommand.h"

using Calc=math::Calculator;

namespace command {

    class AddCommand : public AbstractCommand {
        double value{0};
    public:
        AddCommand()=default;
        ~AddCommand() override = default;

        auto parse(const StringVector &tokens)->void override {
            value = std::stod(tokens[1]);
        }

        auto undo() -> void override {
            Calc::getInstance()->sub(value);
        }

        auto isQuery()->bool override {
            return false;
        }

        auto execute()->void override {
            Calc::getInstance()->add(value);
        }
    };
}