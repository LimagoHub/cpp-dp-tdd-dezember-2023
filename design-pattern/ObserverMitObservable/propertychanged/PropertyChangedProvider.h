//
// Created by JoachimWagner on 29.12.2023.
//

#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include "PropertyChangedEvent.h"
#include "PropertyChangedListener.h"
template<class T>
class PropertyChangedProvider {
    std::vector<PropertyChangedListener<T>*> listeners;
    T* source;

public:
    explicit PropertyChangedProvider(T *source) : source(source) {}
    void notify(const PropertyChangedEvent<T> &event) {
        for (auto listener: listeners)
            listener->propertyChanged(event);
    }
    void subscribe(PropertyChangedListener<T>& listener) { listeners.push_back(&listener); }

};
