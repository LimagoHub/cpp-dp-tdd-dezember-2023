//
// Created by JoachimWagner on 29.12.2023.
//

#pragma once
#include <string>
#include <string_view>
#include <memory>
#include <ostream>


class PersonenBuilder;


class Person {
private:
    std::string vorname;
    std::string nachname;
    std::string ort;
    std::string strasse;


public:
    Person()=default;
    Person(std::string_view vorname_, std::string_view nachname_, std::string_view ort_, std::string_view strasse_);


    [[nodiscard]]const std::string &getVorname() const ;

    void setVorname(std::string_view vorname_) ;

    [[nodiscard]]const std::string &getNachname() const ;

    void setNachname(std::string_view nachname_);

    [[nodiscard]]const std::string &getOrt() const ;

    void setOrt(std::string_view ort_) ;

    [[nodiscard]]const std::string &getStrasse() const ;

    void setStrasse(std::string_view strasse_) ;

    bool operator==(const Person &rhs) const ;

    bool operator!=(const Person &rhs) const ;

    friend std::ostream &operator<<(std::ostream &os, const Person &person) ;

    static PersonenBuilder builder();
};

class PersonenBuilder {
    friend class Person;
    std::shared_ptr<Person> person{new Person{}};
    PersonenBuilder() = default;

public:
    PersonenBuilder & withVorname(std::string_view vorname) {
        person->setVorname(vorname);
        return *this;
    }
    PersonenBuilder & withNachname(std::string_view nachname) {
        person->setNachname(nachname);
        return *this;
    }
    PersonenBuilder & withOrt(std::string_view ort) {
        person->setOrt(ort);
        return *this;
    }
    PersonenBuilder & withStrasse(std::string_view strasse) {
        person->setStrasse(strasse);
        return *this;
    }

    std::shared_ptr<Person> build() {
        return person;
    }
};
