//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once

#include "../math/Calculator.h"

#include "AbstractCommand.h"

namespace command {

    class ClearCommand : public AbstractCommand{

        std::shared_ptr<math::CalculatorMemento> memento{nullptr};

    public:
        ~ClearCommand() override = default;


        auto execute()->void override {
            memento= math::Calculator::getInstance()->getMemento();
            math::Calculator::getInstance()->clear();
        }

        auto undo() -> void override {
            math::Calculator::getInstance()->setMemento(memento);
        }

        auto isQuery()->bool override {
            return false;
        }
    };

} // command
