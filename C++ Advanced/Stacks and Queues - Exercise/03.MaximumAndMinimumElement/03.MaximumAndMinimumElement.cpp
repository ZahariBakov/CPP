#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stack>
#include <sstream>

const int ADD = 1;
const int REMOVE = 2;
const int PRINT_MAX = 3;
const int PRINT_MIN = 4;

std::vector<std::string> readInput() {
    int commandCount = 0;
    std::cin >> commandCount;
    std::cin.ignore();

    std::vector<std::string> commands(commandCount);

    for (std::string& command : commands) {
        getline(std::cin, command);
    }


    return commands;
}

void addElement(std::stack<int>& stackNumbers, int numberToAdd) {
    stackNumbers.push(numberToAdd);
}

void removeElement(std::stack<int>& stackNumbers) {
    if (stackNumbers.empty()) {
        // std::cerr << "Error, request for pop  was received  on an empty stack." << std::endl;
        return;
    }
    stackNumbers.pop();
}

void printMinElement(const std::stack<int>& stackNumbers) {
    std::stack<int> stackNumbersCopy = stackNumbers;
    int smallestNumber = std::numeric_limits<int>::max();

    while (!stackNumbersCopy.empty()) {
        const int cuurentNumber = stackNumbersCopy.top();

        if (cuurentNumber < smallestNumber) {
            smallestNumber = cuurentNumber;
        }

        stackNumbersCopy.pop();
    }

    std::cerr << smallestNumber << std::endl;
}

void printMaxElement(std::stack<int>& stackNumbers) {
    if (stackNumbers.empty()) {
        return;
    }

    std::stack<int> stackNumbersCopy = stackNumbers;
    int biggestNumber = std::numeric_limits<int>::min();

    while (!stackNumbersCopy.empty()) {
        const int cuurentNumber = stackNumbersCopy.top();

        if (cuurentNumber > biggestNumber) {
            biggestNumber = cuurentNumber;
        }

        stackNumbersCopy.pop();
    }

    std::cerr << biggestNumber << std::endl;
}

void processInput(const std::vector<std::string>& commands, 
                  std::stack<int>& stackNumbers) {
    int currCommandId = 0;

    for (const std::string& command : commands) {
        std::istringstream istr(command);
        istr >> currCommandId;

        switch (currCommandId) {
        case ADD: {
            int numberToAdd = 0;
            istr >> numberToAdd;
            addElement(stackNumbers, numberToAdd);
        }
            break;
        case REMOVE:
            removeElement(stackNumbers);
            break;
        case PRINT_MAX:
            printMaxElement(stackNumbers);
            break;
        case PRINT_MIN:
            printMinElement(stackNumbers);
            break;
        default:
            std::cerr << "Error, received unsupportedcommandId: " << currCommandId << std::endl;
            break;
        }
    }
}

void printStackNumbers(std::stack<int>& stackNumbers) {
    if (stackNumbers.empty()) {
        return;
    }

    std::string answer;
    while (!stackNumbers.empty()) {
        answer.append(std::to_string(stackNumbers.top())).append(", ");
        stackNumbers.pop();
    }

    answer.pop_back();
    answer.pop_back();
    std::cout << answer << std::endl;
}

int main() {
    const std::vector<std::string> commands = readInput();
    std::stack<int> stackNumbers;

    processInput(commands, stackNumbers);
    printStackNumbers(stackNumbers);

    return 0;
}
