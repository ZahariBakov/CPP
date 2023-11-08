#include <iostream>
#include <set>
#include <string>
#include <sstream>

std::set<std::string> readInput() {
    std::set<std::string> chemicalElements;
    int num;
    std::cin >> num;

    for (int i = 0; i < num; ++i) {
        std::string input;
        getline(std::cin, input);

        std::istringstream istr(input);
        std::string element;

        while (istr >> element) {
            chemicalElements.insert(element);
        }

    }

    return chemicalElements;
}

void printSolution(std::set<std::string>& chemicalElements) {
    for (std::set<std::string>::iterator it = chemicalElements.begin(); it != chemicalElements.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> chemicalElements = readInput();

    std::cout << std::endl;

    printSolution(chemicalElements);

    return 0;
}
