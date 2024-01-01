//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include "AbstractCounter.h"
namespace processor::handler {


        class CharacterCounter :public AbstractCounter{

        public:
            void process(char c) override {

                    incrementCounter();
            }

        };

    }

