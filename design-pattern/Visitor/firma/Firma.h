//
// Created by JoachimWagner on 27.12.2023.
//

#include <vector>
#include <functional>

#include "../mitarbeiter/AbstractMitarbeiter.h"

using MITARBEITER=mitarbeiter::AbstractMitarbeiter;
using VISITOR=mitarbeiter::visitor::MitarbeiterVisitor;

namespace firma {
    class Firma {

    private:
        std::vector<std::reference_wrapper<MITARBEITER>> mitarbeiters;

    public:
        void add_mitarbeiter(MITARBEITER &mitarbeiter) {
            mitarbeiters.push_back(std::ref(mitarbeiter));
        }

        void iterate (VISITOR & visitor)
        {
            for( auto & m : mitarbeiters)
            {
                //visitor.visit(m);
                m.get().accept(visitor);
            }
        }
    };
}