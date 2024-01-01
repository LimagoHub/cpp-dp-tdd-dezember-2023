//
// Created by JoachimWagner on 25.12.2023.
//

#pragma once
#include <stdexcept>
#include "../TrafficLight.h"
#include "TrafficLightState.h"


namespace state {
class AbstractTrafficLightState : public state::TrafficLightState {
    private:
        trafficlight::TrafficLight *trafficLight_;
    protected:
        explicit AbstractTrafficLightState(trafficlight::TrafficLight *trafficLight) : trafficLight_(trafficLight) {}


public:
        ~AbstractTrafficLightState() override = default;

        std::string getColor() override{
            throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
        }

        void nextColor() override {
            throw std::logic_error("Diese Funktion macht hier keinen Sinn.");
        }

        trafficlight::TrafficLight *getTrafficLight() const {
            return trafficLight_;
        }

};
}
