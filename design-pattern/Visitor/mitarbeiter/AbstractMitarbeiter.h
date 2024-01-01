//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <string>
#include <ostream>
#include "visitor/MitarbeiterVisitor.h"

namespace mitarbeiter {
    class AbstractMitarbeiter {
        std::string name;
    public:

        explicit AbstractMitarbeiter(const std::string &name = "Fritz") : name(name) {}

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            AbstractMitarbeiter::name = name;
        }

        friend std::ostream &operator<<(std::ostream &os, const AbstractMitarbeiter &mitarbeiter) {
            os << "name: " << mitarbeiter.name;
            return os;
        }

        virtual void accept(visitor::MitarbeiterVisitor& visitor)  = 0;
    };
}