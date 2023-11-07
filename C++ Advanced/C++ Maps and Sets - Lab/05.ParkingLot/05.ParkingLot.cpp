#include <iostream>
#include <sstream>
#include <list>

std::list<std::string> readInput() {
    std::list<std::string> parkinglot;

    while (true) {
        std::string input;
        getline(std::cin, input);

        if (input == "END") {
            break;
        }

        std::istringstream istr(input);
        std::string command, carNumber;
        istr >> command;
        istr >> carNumber;

        if (command == "IN,") {
            parkinglot.push_back(carNumber);
        }
        else {
            parkinglot.remove(carNumber);
        }
    }

    return parkinglot;
}

void printSolution(const std::list<std::string>& parkinglot) {
    if (parkinglot.empty()) {
        std::cout << "Parking Lot is Empty" << std::endl;
    }
    else {
        for (std::string car : parkinglot) {
            std::cout << car << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::list<std::string> parkinglot = readInput();

    printSolution(parkinglot);

    return 0;
}
