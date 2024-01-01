#include <iostream>
#include "tiere/Tier.h"
#include "tiere/Schwein.h"
#include <functional>
using namespace std::placeholders;

class Metzger {
public:
    /*void schlachten(const Tier &tier) const{
        std::cout << "Messer wetz" << std::endl;
    }*/
    void schlachten(Tier * tier) const {
        std::cout << "Messer wetz" << std::endl;
    }
};
static void foo(const Metzger &metzger, const Tier &tier);

class Demo {
    Metzger metzger;
    std::function<void(Tier *)> metzgerPointer;

public:

    //explicit Demo() : metzgerPointer(std::bind(&Metzger::schlachten, metzger,_1)) {}
    explicit Demo() : metzgerPointer([&metzger=metzger](Tier * s){metzger.schlachten(s);}) {}

    void run() {
        Schwein piggy{"Miss Piggy"};




        piggy.addPigTooFatListener(metzgerPointer);
        for (int i = 0; i < 11; ++i) {
            piggy.fuettern();
        }
    }
};



int main() {

    Demo d;
    d.run();
    return 0;
}
