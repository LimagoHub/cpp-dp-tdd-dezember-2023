//
// Created by JoachimWagner on 18.07.2023.
//

#pragma once
#include "abstract_node.h"

namespace de::limago {

    class leaf :
            public abstract_node {
    public:
        leaf(const std::string &name)
                : abstract_node(name) {
        }

        auto print(std::ostream &os) const -> void override {
            os << std::string{"Leaf: "};
            abstract_node::print(os);
        }
    };
}