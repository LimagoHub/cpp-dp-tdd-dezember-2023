//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
namespace mitarbeiter {
    class GehaltsEmpfaenger;
    class LohnEmpfaenger;
}

namespace mitarbeiter::visitor {
    // Contract
    class MitarbeiterVisitor {

    public:
        virtual void visit(mitarbeiter::LohnEmpfaenger &lohn_empfaenger) = 0;

        virtual void visit(mitarbeiter::GehaltsEmpfaenger &gehalts_empfaenger) = 0;

    };
}