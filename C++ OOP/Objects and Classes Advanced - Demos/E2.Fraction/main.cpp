#include <iostream>
#include <set>
#include <vector>

#include "Fraction.h" 

int main() {
    Fraction first(2, 10);
    Fraction second{ 0, 1 };

    std::cin >> second;
    std::cout << second << std::endl;

    // This is one way with "equal".
    //if (first == second)

    // This is other way with operator "==".
    if (first == second) {
        std::cout << "equal" << std::endl;
    }
    else {
        std::cout << "not equal" << std::endl;
    }

    // Postfix operator
    //first++;

    // Prefix operator
    ++++++++++first;
    std::cout << first << std::endl;

    std::set<Fraction> numbers{ first, second };
    numbers.insert(Fraction(6, 30));

    std::vector<Fraction> numbersVec = { first, second };
    std::vector<Fraction> numbersVec2 = { first };
    numbersVec2.push_back(second);

    if (numbersVec == numbersVec2) {
        std::cout << "vectors are equal";
    }
    else {
        std::cout << "vectors are not equal";
    }
    std::cout << std::endl;

    return 0;
}
