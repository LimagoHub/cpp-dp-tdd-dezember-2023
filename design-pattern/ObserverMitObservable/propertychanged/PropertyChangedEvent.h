//
// Created by JoachimWagner on 29.12.2023.
//

#pragma once
#include <string>
#include <variant>
#include <ostream>

template<class T>
class PropertyChangedEvent {
    const T *source;
    std::string propertyName;
    const std::variant<std::string, unsigned > oldValue;
    const std::variant<std::string, unsigned > newValue;

public:
    PropertyChangedEvent(const T *source,
                         std::string propertyName,
                         std::variant<std::string, unsigned int> oldValue,
                         std::variant<std::string, unsigned int> newValue) :

                         source(source), propertyName(propertyName), oldValue(oldValue), newValue(newValue) {}

    const T *getSource() const {
        return source;
    }

    const std::string &getPropertyName() const {
        return propertyName;
    }

    const std::variant<std::string, unsigned int> &getOldValue() const {
        return oldValue;
    }

    const std::variant<std::string, unsigned int> &getNewValue() const {
        return newValue;
    }

    friend std::ostream &operator<<(std::ostream &os, const PropertyChangedEvent<T> &event) {
        os << "source: " << *(event.source) << " propertyName: " << event.propertyName;
        if(std::holds_alternative<unsigned>(event.oldValue)) {
            os << " oldValue: " << std::get<unsigned>(event.oldValue) <<
                  " newValue: "  << std::get<unsigned>(event.newValue);
        } else {
            os << " oldValue: " << std::get<std::string>(event.oldValue) <<
               " newValue: "  << std::get<std::string>(event.newValue);
        }


        return os;
    }
};
