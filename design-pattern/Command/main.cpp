#include <iostream>
#include <string>
#include "command/CommandFactory.h"
#include "command/CommandHistory.h"

using Factory=command::CommandFactory;
using History=command::CommandHistory;

auto main()-> int {

    History history;
    std::string line;
    while(true) {
        std::cout << "#>";
        std::getline(std::cin, line);
        if(line == "ende") break;
        if(line == "undo") {
            history.undo();
            continue;
        }
        if(line == "redo") {
            history.redo();
            continue;
        }
        auto command = Factory::create(line);
        if(command.get() == nullptr) {
            std::cout << "Unbekannter Befehl" << std::endl;
            continue;
        }
        command->execute();
        history.add(command);
    }


    return 0;
}
