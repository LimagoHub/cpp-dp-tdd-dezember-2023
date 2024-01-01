//
// Created by JoachimWagner on 29.12.2023.
//

#pragma once
#include <variant>
#include <string_view>
#include "PropertyChangedEvent.h"
template<class T>
class PropertyChangedListener {
public:
    virtual void propertyChanged(const PropertyChangedEvent<T> & event)=0;
};
