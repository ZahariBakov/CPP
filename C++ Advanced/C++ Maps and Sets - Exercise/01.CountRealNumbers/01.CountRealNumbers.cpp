#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

std::vector<double> readInput() {
    std::vector<double> numbers;

    double CurrNum = 0.0;
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    while (istr >> CurrNum) {
        numbers.push_back(CurrNum);
    }

    return numbers;
}

std::map<double, int> produceCountMap(const std::vector<double>& numbers) {
    std::map<double, int> countMap;

    for (double num : numbers) {
        countMap[num]++;
    }

    return countMap;
}

void printSolution(const std::map<double, int>& countMap) {
    for (const std::pair<double, int>& pair : countMap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}

int main() {
    const std::vector<double> numbers = readInput();
    const std::map<double, int> countMap = produceCountMap(numbers);
    printSolution(countMap);

    return 0;
}
