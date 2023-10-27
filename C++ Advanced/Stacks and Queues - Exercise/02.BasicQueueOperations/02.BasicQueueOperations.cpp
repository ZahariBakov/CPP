#include <iostream>
#include <queue>
#include <string>
#include <limits>

std::queue<int> readInput(int& numbersToRemove, int& targetNumber) {
    std::queue<int> numbers;
    int inputNumbersCount = 0;

    std::cin >> inputNumbersCount;
    std::cin >> numbersToRemove;
    std::cin >> targetNumber;

    int currentNumber = 0;

    for (int i = 0; i < inputNumbersCount; ++i) {
        std::cin >> currentNumber;
        numbers.push(currentNumber);
    }

    return numbers;
}

void removeElement(const int numbersToRemove, std::queue<int>& stackNumbers) {
    if (stackNumbers.size() < (size_t)numbersToRemove) {
        // sanity check
        std::cerr << "Invalid input, stack size is: " << stackNumbers.size()
            << ", while numberToRemove is: " << numbersToRemove << std::endl;
    }

    for (int i = 0; i < numbersToRemove; ++i) {
        stackNumbers.pop();
    }
}

std::string findSolution(const int targetNumber, std::queue<int>& stackNumbers) {
    std::string result;

    if (stackNumbers.empty()) {
        return "0";
    }

    int currentNumber = 0;
    int smallesNumber = std::numeric_limits<int>::max();

    while (!stackNumbers.empty()) {
        currentNumber = stackNumbers.front();

        if (currentNumber == targetNumber) {
            return "true";
        }

        if (smallesNumber > currentNumber) {
            smallesNumber = currentNumber;
        }

        stackNumbers.pop();
    }

    return std::to_string(smallesNumber);
}

void printSolution(const std::string& answer) {
    std::cout << answer << std::endl;
}

int main() {
    int numbersToRemove = 0;
    int targetNumber = 0;

    std::queue<int> stackNumbers = readInput(numbersToRemove, targetNumber);
    removeElement(numbersToRemove, stackNumbers);
    const std::string result = findSolution(targetNumber, stackNumbers);
    printSolution(result);

    return 0;
}
