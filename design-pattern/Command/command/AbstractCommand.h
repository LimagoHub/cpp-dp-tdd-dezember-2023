//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include "Command.h"
#include <stdexcept>
namespace command {
    class AbstractCommand: public Command{
    public:
        ~AbstractCommand() override = default;

        auto parse(const StringVector &tokens) -> void override {

        }


        auto undo() ->void override {
            throw std::logic_error("Upps");
        }

        auto isQuery()->bool override {
            return true;
        }
    };
}
