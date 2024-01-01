//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <iostream>
#include "AbstractTrafficLightState.h"
namespace state {
    class GreenState : public state::AbstractTrafficLightState{

    public:
        GreenState(trafficlight::TrafficLight *trafficLight) : AbstractTrafficLightState(trafficLight) {}

        std::string getColor() {
            return "GREEN";
        }

        void nextColor() {
            getTrafficLight()->current = getTrafficLight()->red;
        }



        ~GreenState() override{
            std::cout << "Green destroyed" << std::endl;
        }

    };
}
