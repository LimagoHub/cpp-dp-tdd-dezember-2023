#include <iostream>
#include "client/CalculatorClient.h"
#include "math/CalculatorFactory.h"

int main() {
    math::CalculatorFactory::setLogger(false);
    auto calculator = math::CalculatorFactory::create();
    clients::CalculatorClient client {std::move(calculator)};
    client.go();
    return 0;
}
