#include "converter.hpp"
#include <iostream>

int main()
{
    UnitConverter converter;
    std::string input;

    std::cout << "=== Smart Unit Converter ===\n";
    while (true)
    {
        std::cout << "\nEnter value with unit (e.g., '10 km', '25°C', '100 lb') or 'exit': ";
        std::getline(std::cin, input);

        if (input == "exit")
            break;

        auto result = converter.convert(input);
        if (result)
            std::cout << *result << "\n";
        else
            std::cout << "Invalid input. Try again.\n";
    }

    return 0;
}