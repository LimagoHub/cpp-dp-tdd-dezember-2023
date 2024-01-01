#include <iostream>
#include "Singleton.h"
int main() {

    auto s1 = Singleton::getInstance();
    auto s2 = Singleton::getInstance();

    s1->increment();


    std::cout << s2->getCounter() << std::endl;
    return 0;
}
