//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include "FileHandler.h"
namespace processor::handler {

    class AbstractFileHandler: public FileHandler{
    public:
        ~AbstractFileHandler() override = default;

        void init() override {
            // OK
        }

        void dispose() override {
            // OK
        }
    };
}
