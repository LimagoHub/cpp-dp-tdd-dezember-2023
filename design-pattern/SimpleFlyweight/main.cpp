#include <iostream>
#include "AttributedCharacter.h"

int main()
{

    auto a1 = AttributedCharacter::get_instance('A', false);
    auto a2 = AttributedCharacter::get_instance('A', false);

    std::cout << (a1 == a2) << std::endl;
    auto a3 = AttributedCharacter::get_instance('A', true);

    std::cout << (a1 == a3) << std::endl;

    std::cout << "Hello World!\n";



}