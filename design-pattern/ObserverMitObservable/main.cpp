#include <iostream>
#include "propertychanged/PropertyChangedListener.h"
#include "tiere/Schwein.h"

class MyListener :public PropertyChangedListener<Schwein>{

public:
    void propertyChanged(const PropertyChangedEvent<Schwein> &event) override {
        std::cout << event << std::endl;
    }

};

int main() {
    MyListener demo;
    Schwein piggy;
    piggy.subscribe(demo);
    piggy.setName("babe");
    piggy.fuettern();

    return 0;
}
