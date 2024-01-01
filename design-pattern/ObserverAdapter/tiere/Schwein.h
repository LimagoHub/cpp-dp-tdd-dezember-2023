//
// Created by JoachimWagner on 29.12.2023.
//

#pragma once
#include <memory>
#include <string>
#include <vector>
#include <ostream>
#include <functional>

#include "Tier.h"

class Schwein :public Tier{

    inline static const unsigned MAX_WEIGHT{ 20};

    std::vector<std::function<void(Schwein*)>> listeners;
    std::string name;
    unsigned gewicht{10};

    void setGewicht(unsigned int gewicht_) {
        Schwein::gewicht = gewicht_;
        if(Schwein::gewicht > MAX_WEIGHT) firePigTooFatEvent();
    }
    
    void firePigTooFatEvent(){
        for (const auto & listener:listeners) {
            listener(this);
        }
    }

public:
    explicit Schwein(std::string_view name_="Nobody") : name(name_) {}

    void addPigTooFatListener(const std::function<void(Schwein*)> &listener) {
        listeners.emplace_back(listener);
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    void setName(std::string_view name_) {
        Schwein::name = name_;
    }

    [[nodiscard]] unsigned int getGewicht() const {
        return gewicht;
    }


    void fuettern() {
        setGewicht(getGewicht() + 1);
    }


    bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }
};
