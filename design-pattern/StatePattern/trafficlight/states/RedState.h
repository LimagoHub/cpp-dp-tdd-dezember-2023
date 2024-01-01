//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include "AbstractTrafficLightState.h"
namespace state {
    class RedState : public state::AbstractTrafficLightState {

    private:

    public:
        RedState(trafficlight::TrafficLight *trafficLight) : AbstractTrafficLightState(trafficLight) {}
        std::string getColor() {
            return "RED";
        }

        void nextColor() {
            getTrafficLight()->current = getTrafficLight()->green;
        }


    };
}
