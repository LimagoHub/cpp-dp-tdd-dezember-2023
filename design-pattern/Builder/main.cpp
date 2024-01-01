#include <iostream>
#include "builder/Person.h"

int main() {

    auto person = Person::builder()
            .withVorname("John")
            .withNachname("Doe")
            .withOrt("Nowhere")
            .withStrasse("Elmstreet")
            .build();

    auto p = Person{.vorname="Jane",.nachname="Doe",.ort="Ffm",.strasse=""};
    std::cout << p << std::endl;
    return 0;
}
