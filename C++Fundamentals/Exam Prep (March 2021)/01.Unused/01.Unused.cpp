#include <iostream>
#include <string>
#include <array>

const int alphabetSize = 26;

std::string readInput() {
    std::string line;
    getline(std::cin, line);

    return line;
}

void printSolution(std::array<bool, alphabetSize>& foundLetters) {
    size_t size = foundLetters.size();

    for (int i = 0; i < size; ++i) {
        if (!foundLetters[i]) {
            std::cout << char(i + 'a');
        }
    }
}

void markFoundLetters(const std::string& line, 
                      std::array<bool, alphabetSize>& foundLetters) {
    for (const char letter : line) {
        const int letterIdx = letter - 'a';
        foundLetters[letterIdx] = true;
    }
}

int main() {
    const std::string text = readInput();
    
    std::array<bool, alphabetSize> foundLetters { };

    markFoundLetters(text, foundLetters);

    printSolution(foundLetters);

    return 0;
}