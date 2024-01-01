//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <ostream>
#include "AbstractMitarbeiter.h"
namespace mitarbeiter{
    class GehaltsEmpfaenger :
            public AbstractMitarbeiter {
    private:
        double gehalt;


    public:
        GehaltsEmpfaenger(const std::string& name, double gehalt=1000)
                : AbstractMitarbeiter(name),
                  gehalt(gehalt)
        {
        }


        double get_gehalt() const
        {
            return gehalt;
        }

        void set_gehalt(const double gehalt)
        {
            this->gehalt = gehalt;
        }

        void accept(visitor::MitarbeiterVisitor& visitor)  override
        {
            visitor.visit(*this);

        }

        friend std::ostream& operator<<(std::ostream& os, const GehaltsEmpfaenger& obj)
        {
            return os
                    << "Gehaltsempfaenger: "
                    << static_cast<const AbstractMitarbeiter&>(obj)
                    << " gehalt: " << obj.gehalt;
        }
    };
}