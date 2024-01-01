//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <memory>
#include "states/TrafficLightState.h"
namespace state {
    class GreenState;
    class RedState;
}

namespace trafficlight {
    class TrafficLight {


    private:
        std::shared_ptr<state::TrafficLightState>  red;
        std::shared_ptr<state::TrafficLightState> green;
        std::shared_ptr<state::TrafficLightState> current;

    public:
        TrafficLight();
        std::string getColor() ;

        void nextColor() ;

        friend class state::RedState;
        friend class state::GreenState;
    };
}
