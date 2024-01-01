//
// Created by JoachimWagner on 25.12.2023.
//
#include <string>
#pragma once
namespace state {

    class TrafficLightState {
            public:
            virtual ~TrafficLightState() = default;
            virtual std::string getColor() = 0;    // Business
            virtual void nextColor() = 0; // Statuswechsel

    };

}
