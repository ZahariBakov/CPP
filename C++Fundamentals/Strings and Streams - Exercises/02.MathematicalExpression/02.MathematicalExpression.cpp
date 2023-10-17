#include <iostream>
#include <string>

std::string readInput() {
    std::string line;
    getline(std::cin, line);
    return line;
}

int countBrackets(const std::string& input) {
    int brackets = 0;

    for (const char c : input) {
        if (brackets < 0) {
            return -1;
        }

        if (c == '(') {
            brackets += 1;
        }
        else if (c == ')') {
            brackets -= 1;
        }
    }

    return brackets;
}

void printResult(int brackets) {
    if (brackets != 0) {
        std::cout << "incorrect" << std::endl;
    }
    else {
        std::cout << "correct" << std::endl;
    }
}

int main() {
    const std::string input = readInput();
    int brackets = countBrackets(input);
    printResult(brackets);

    return 0;
}
