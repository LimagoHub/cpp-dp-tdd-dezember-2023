//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once


#include "../persistence/person.h"

class BlacklistService {
public:
    virtual bool is_blacklisted(const person &possible_blacklisted_person) const = 0;
};
