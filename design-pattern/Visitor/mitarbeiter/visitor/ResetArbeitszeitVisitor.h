#pragma once

#include "AbstractMitarbeiterVisitor.h"
#include "../LohnEmpfaenger.h"
#include "../GehaltsEmpfaenger.h"

namespace mitarbeiter::visitor {

    class ResetArbeitszeitVisitor :
            public AbstractMitarbeiterVisitor {
    public:
        void visit(LohnEmpfaenger &lohn_empfaenger) override {
            lohn_empfaenger.set_arbeitszeit(0);
        }

    };

}