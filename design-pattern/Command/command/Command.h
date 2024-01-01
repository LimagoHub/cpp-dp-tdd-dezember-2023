//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <string>
#include <vector>

namespace command {
    using StringVector=std::vector<std::string>;

    class Command {
    public:
        virtual ~Command()=default;
        virtual auto parse(const StringVector &tokens) ->void = 0;
        virtual auto execute()->void = 0;
        virtual auto undo()->void = 0;
        virtual auto isQuery()->bool = 0;
    };
}
