//
// Created by JoachimWagner on 28.12.2023.
//

#pragma once
#include <stack>
#include <memory>
#include <iostream>
#include "Command.h"

namespace command {

    class CommandHistory {
        using CommandPointer = std::shared_ptr<Command>;

        std::stack<CommandPointer> undoStack;
        std::stack<CommandPointer> redoStack;

    public:
        CommandHistory()= default;
        auto add(const CommandPointer &c )->void{
            if(c->isQuery()) return;
            std::stack<CommandPointer>().swap(redoStack);
            undoStack.push(c);
        }

        auto undo()->void {
            if(undoStack.empty()){
                std::cout << "Can't undo";
            }
            else {
                auto command = undoStack.top();
                undoStack.pop();
                command->undo();
                redoStack.push(command);
            }
        }

        auto redo() ->void{
            if(redoStack.empty()){
                std::cout << "Can't redo";
            }
            else {
                auto command = redoStack.top();
                redoStack.pop();
                command->execute();
                undoStack.push(command);
            }
        }
    };

}
