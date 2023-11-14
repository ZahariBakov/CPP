#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

std::set<double, std::greater<double> > readInput() {
    std::set<double, std::greater<double> > numbers;
    std::string input;
    double num;

    getline(std::cin, input);

    std::istringstream istr(input);

    while (istr >> num) {
        numbers.insert(num);
    }

    return numbers;
}

void printSolution(std::set<double, std::greater<double> >& numbers) {
    int n = 3;

    for (std::set<double>::iterator i = numbers.begin(); i != numbers.end() && n; ++i, --n) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<double, std::greater<double> > numbers = readInput();

    printSolution(numbers);

    return 0;
}
