#include <iostream>
#include "src/composite/node.h"
using node = de::limago::node;
int main() {


    auto root =std::make_shared<node>("root");

    auto e1 = std::make_shared<node>("e1");
    auto e2 = std::make_shared<node>("e2");
    auto e3 = std::make_shared<node>("e3");
    auto e3_1 = std::make_shared<node>("e3_1");
    auto e3_2 = std::make_shared<node>("e3_2");
    auto e3_3 = std::make_shared<node>("e3_3");

    root->append(e1);
    root->append(e2);
    root->append(e3);

    e3->append(e3_1);
    e3->append(e3_2);
    e3->append(e3_3);

    for(auto &item : *root) {
        std::cout << item << std::endl;

    }

    auto expr = std::find(root->begin(), root->end(), *e3_3);

    std::cout << "---------" << std::endl;

    while(expr != root->end()) {
        std::cout << *expr << std::endl;
        --expr;

    }





    return 0;
}
