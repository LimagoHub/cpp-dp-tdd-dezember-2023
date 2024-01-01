//
// Created by JoachimWagner on 27.12.2023.
//

#pragma once
#include <memory>

class Singleton {
private:
    static std::shared_ptr<Singleton> instance;
    Singleton()=default;
    int counter{0};
public:
    virtual ~Singleton()=default;
    Singleton& operator=(const Singleton& other) = delete;

    static std::shared_ptr<Singleton> getInstance() {
       if(Singleton::instance.get() == nullptr)
           Singleton::instance.reset(new Singleton{});
        return Singleton::instance;
    }

    int getCounter() const {
        return counter;
    }

    void increment() {
        ++counter;
    }

};
std::shared_ptr<Singleton> Singleton::instance = nullptr;