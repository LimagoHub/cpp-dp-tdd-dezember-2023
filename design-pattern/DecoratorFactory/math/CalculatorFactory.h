//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <memory>
#include "CalculatorImpl.h"
#include "CalculatorLogger.h"
#include "CalculatorBenchmark.h"
using Calc_Pointer = std::unique_ptr<math::Calculator>;

namespace math {
    class CalculatorFactory {
        inline static bool logger{true};
        inline static bool benchmark{true};
    public:
        static bool isLogger(){return logger;}
        static void setLogger(bool logger_) {CalculatorFactory::logger = logger_;}
        static bool isBenchmark(){return benchmark;}
        static void setBenchmark(bool benchmark_){ CalculatorFactory::benchmark = benchmark_;}

        static Calc_Pointer create() {
            auto result = Calc_Pointer(new CalculatorImpl());
            if(isLogger()) result = Calc_Pointer(new CalculatorLogger(std::move(result)));
            if(isBenchmark()) result = Calc_Pointer(new CalculatorBenchmark(std::move(result)));
            return result;
        }
    };
}



