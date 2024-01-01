//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <iostream>
#include <memory>
#include "CalculatorMemento.h"

namespace math {
    class Calculator {
        inline static std::shared_ptr<Calculator> instance{nullptr};
        double memory{0};

        class ConcreteCalculatorMemento : public CalculatorMemento {
            const double memory;
        public:
            explicit ConcreteCalculatorMemento(const double memory) : memory(memory) {}

            [[nodiscard]] auto getMemory() const ->double {
                return memory;
            }
        };

    public:

        auto setMemento(const std::shared_ptr<CalculatorMemento> &calculatorMemento) -> void {
            auto memento = static_cast<ConcreteCalculatorMemento*>(calculatorMemento.get());

            Calculator::memory = memento->getMemory();
        }

        [[nodiscard]] auto getMemento()->std::shared_ptr<CalculatorMemento> {
            return std::make_shared<ConcreteCalculatorMemento>(Calculator::memory);
        }


        [[nodiscard]]auto getMemory() const->double {
            return memory;
        }

        auto setMemory(double memory_)->void {
            Calculator::memory = memory_;
        }


        [[nodiscard]] static auto getInstance()->std::shared_ptr<Calculator>  {
            if(instance == nullptr)
                instance.reset(new Calculator{});
            return instance;
        }

        auto print() const->void{
            std::cout << memory << std::endl;
        }
        auto clear()-> void {
            memory = 0;
        }

        auto add(double value)-> void {
            memory += value;
        }
        auto sub(double value)-> void {
            memory -= value;
        }
        auto mult(double value)-> void {
            memory *= value;
        }
        auto div(double value)-> void {
            memory /= value;
        }

    };
}
