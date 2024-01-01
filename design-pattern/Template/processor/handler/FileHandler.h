//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once

namespace processor::handler {
    class FileHandler {
    public:
        virtual ~FileHandler() = default;

        virtual void init() = 0;

        virtual void dispose() = 0;

        virtual void process(char c) = 0;
    };
}
