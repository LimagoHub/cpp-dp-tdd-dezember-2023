//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <iostream>
#include "AbstractFileHandler.h"
namespace processor::handler {

    class AbstractCounter: public AbstractFileHandler{
        unsigned counter{0};

    protected:
        void incrementCounter() {
            ++counter;
        }
    public:
       [[nodiscard]] unsigned int getCounter() const {
            return counter;
        }


        ~AbstractCounter() override = default;

        void init() override {
            counter = 0;
        }

        void dispose() override {
            std::cout << "Anzahl = " << getCounter() << std::endl;
        }
    };
}