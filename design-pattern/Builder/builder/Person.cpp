//
// Created by JoachimWagner on 29.12.2023.
//
#include "Person.h"

Person::Person(std::string_view vorname_, std::string_view nachname_, std::string_view ort_,
               std::string_view strasse_) : vorname(vorname_), nachname(nachname_), ort(ort_), strasse(strasse_) {}

const std::string &Person::getVorname() const {
    return vorname;
}

void Person::setVorname(std::string_view vorname_) {
    Person::vorname = vorname_;
}

const std::string &Person::getNachname() const {
    return nachname;
}

void Person::setNachname(std::string_view nachname_)  {
    Person::nachname = nachname_;
}

const std::string &Person::getOrt() const {
    return ort;
}

void Person::setOrt(std::string_view ort_) {
    Person::ort = ort_;
}

const std::string &Person::getStrasse() const {
    return strasse;
}

void Person::setStrasse(std::string_view strasse_) {
    Person::strasse = strasse_;
}

bool Person::operator==(const Person &rhs) const {
    return vorname == rhs.vorname &&
           nachname == rhs.nachname &&
           ort == rhs.ort &&
           strasse == rhs.strasse;
}

bool Person::operator!=(const Person &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "vorname: " << person.vorname << " nachname: " << person.nachname << " ort: " << person.ort
       << " strasse: " << person.strasse;
    return os;
}

PersonenBuilder Person::builder() {
    return PersonenBuilder{};
}





