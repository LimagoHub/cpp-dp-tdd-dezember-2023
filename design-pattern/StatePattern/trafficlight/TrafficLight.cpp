//
// Created by JoachimWagner on 25.12.2023.
//

#include "TrafficLight.h"
#include "states/RedState.h"
#include "states/GreenState.h"

trafficlight::TrafficLight::TrafficLight():
    red(std::make_shared<state::RedState>(this)) ,
    green(std::make_shared<state::GreenState>(this)),
    current(red)
    {}

std::string trafficlight::TrafficLight::getColor() {
    return current->getColor();
}

void trafficlight::TrafficLight::nextColor() {
    current->nextColor();
}
