#include <iostream>

#include "Company.h"

int main() {
    Company c(42, "TheAnswer Inc.", { { 'G', 'L' },{ 'H', 'F' },{ 'G', 'G' } });

    std::cout << c + " " << std::endl;

    c += { 'W', 'P' };

    std::cout << c + " " << std::endl;

    std::cout << c + " <- this is a cool company" << std::endl;

    return 0;
}