#include <iostream>
#include <set>
#include <string>
#include <sstream>

void readInput(std::set<double>& numbers) {
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    double num = 0.0;

    while (istr >> num) {
        numbers.insert(num);
    }
}

void printSolution(std::set<double>& numbers) {
    for (auto i = numbers.begin(); i != numbers.end(); ++i) {
        std::cout << *i << (i != --numbers.end() ? " <= " : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::set<double> numbers;
    readInput(numbers);
    printSolution(numbers);

    return 0;
}
