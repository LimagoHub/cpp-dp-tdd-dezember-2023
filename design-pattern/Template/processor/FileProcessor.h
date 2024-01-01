//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "handler/FileHandler.h"

namespace processor {
    class FileProcessor {
    public:
        void addHandler(handler::FileHandler &handler){
            handlers.push_back(std::ref(handler));
        }

        void run(std::string filename) {
            std::fstream fin(filename, std::ios::in);
            if(! fin.is_open()) {
                std::cout << "Fehler beim Oeffnen von " << filename << std::endl;
                return;
            }
            init();
            int ch;

            while (EOF != (ch = fin.get()))
            {
                process(static_cast<char>( ch));
            }
            dispose();
        }

    private:
        std::vector < std::reference_wrapper<handler::FileHandler>> handlers;
        void init() {
            for(auto & handler: handlers)
                handler.get().init();
        }

        void dispose() {
            for(auto & handler: handlers)
                handler.get().dispose();
        }

        void process(char c)  {
            for(auto & handler: handlers)
                handler.get().process(c);
        }

    };
}
