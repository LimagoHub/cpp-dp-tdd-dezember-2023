//
// Created by JoachimWagner on 01.06.2023.
//

#pragma once


#include <exception>
#include <string>

class personen_service_exception : public std::exception
{
private:
    std::string errorMessage;
    std::exception_ptr nestedException;
public:
    personen_service_exception(const std::string& message, std::exception_ptr nestedException = nullptr)
            : errorMessage(message), nestedException(nestedException) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

    std::exception_ptr getNestedException() const {
        return nestedException;
    }

};
