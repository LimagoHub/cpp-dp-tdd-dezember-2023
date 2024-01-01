#include <iostream>
#include "processor/FileProcessor.h"
#include "processor/handler/CharacterCounter.h"

using CharCounter = processor::handler::CharacterCounter;
using Processor = processor::FileProcessor;

int main() {

    CharCounter charCounter;

    Processor fileProcessor;
    fileProcessor.addHandler(charCounter);
    fileProcessor.run("..\\data\\blind.txt");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
