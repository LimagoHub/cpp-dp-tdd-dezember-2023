//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <memory>
#include <vector>
#include <string>
#include <sstream>

#include "Command.h"
#include "PrintCommand.h"
#include "AddCommand.h"
#include "ClearCommand.h"


namespace command {
    using CommandPointer = std::shared_ptr<Command>;

    class CommandFactory {

    public:
        static auto create(const std::string &row)->CommandPointer {
            CommandPointer result{nullptr};
            auto tokens = split(row);
            if(tokens[0]=="Print"){
                result.reset(new PrintCommand());
                result->parse(tokens);
            }
            if(tokens[0]=="Add"){
                result.reset(new AddCommand());
                result->parse(tokens);
            }
            if(tokens[0]=="Clear"){
                result.reset(new ClearCommand());
                result->parse(tokens);
            }
            return result;
        }

        static auto split(const std::string &row)->StringVector {
            std::vector<std::string> tokens;
            std::stringstream ss(row);
            std::string token;
            while(ss >> token) {
                tokens.push_back(token);
            }
            return tokens;
        }

    };
}
