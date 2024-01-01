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
#include "../propertychanged/PropertyChangedProvider.h"
class Schwein :public Tier{

    PropertyChangedProvider<Schwein> provider{this};
    inline static const unsigned MAX_WEIGHT{ 20};

    std::vector<std::function<void(Schwein*)>> listeners;
    std::string name;
    unsigned gewicht{10};

    void setGewicht(unsigned int gewicht_) {
        provider.notify(PropertyChangedEvent{this, "gewicht",Schwein::gewicht, Schwein::gewicht = gewicht_});

    }
    


public:
    explicit Schwein(std::string_view name_="Nobody") :  name(name_) {}

    void subscribe(PropertyChangedListener<Schwein>& listener) { provider.subscribe(listener); }
    //void unsubscribe(PropertyChangedListener<Schwein>& listener) { provider.unsubscribe(listener);}

    void setName(std::string_view name_) {

        PropertyChangedEvent<Schwein> event {this, "name",Schwein::name, Schwein::name = name_};
        provider.notify(event);

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
