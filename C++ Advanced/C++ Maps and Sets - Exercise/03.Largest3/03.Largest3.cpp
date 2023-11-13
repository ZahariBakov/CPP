#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<double> readInput() {
    std::vector<double> numbers;
    std::string input;
    double num;

    getline(std::cin, input);

    std::istringstream istr(input);

    while (istr >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

void orderNumbers(std::vector<double>& numbers) {
    std::sort(numbers.begin(), numbers.end(), std::greater<double>());
}

void printSolution(std::vector<double>& numbers) {
    int size = numbers.size();
    if (size > 3) {
        size = 3;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    auto numbers = readInput();
    orderNumbers(numbers);
    printSolution(numbers);

    return 0;
}
