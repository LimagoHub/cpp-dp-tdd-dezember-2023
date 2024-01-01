#include <iostream>
#include "mitarbeiter/GehaltsEmpfaenger.h"
#include "mitarbeiter/LohnEmpfaenger.h"
#include "firma/Firma.h"
#include "mitarbeiter/visitor/PrintVisitor.h"
#include "mitarbeiter/visitor/ResetArbeitszeitVisitor.h"

using GEHALTSEMPFAENGER=mitarbeiter::GehaltsEmpfaenger;
using LOHNEMPFAENGER=mitarbeiter::LohnEmpfaenger;
using FIRMA=firma::Firma;


int main() {

    GEHALTSEMPFAENGER g1("Schmidt", 2000);
    GEHALTSEMPFAENGER g2("Mueller", 1500);
    LOHNEMPFAENGER    lohn1("Hinz", 20, 20);
    LOHNEMPFAENGER    lohn2("Kunz", 15, 20);
    GEHALTSEMPFAENGER g3("Mayer", 1500);


    FIRMA firma;

    firma.add_mitarbeiter(g1);
    firma.add_mitarbeiter(g2);
    firma.add_mitarbeiter(lohn1);
    firma.add_mitarbeiter(lohn2);
    firma.add_mitarbeiter(g3);


    mitarbeiter::visitor::PrintVisitor p{};
    mitarbeiter::visitor::ResetArbeitszeitVisitor rav{};

    firma.iterate(p);
    std::cout << "-------------------------------\n";
    firma.iterate(rav);
    firma.iterate(p);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
