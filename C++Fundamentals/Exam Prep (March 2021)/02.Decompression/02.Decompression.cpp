#include <iostream>
#include <string>

std::string readInput() {
    std::string line;
    getline(std::cin, line);

    return line;
}

int getIntFromChar(char c) {
    return c - '0';
}

std::string decompres (const std::string& compressedString) {
    std::string decompressedString;
    int repetition = 0;

    for (const char letter : compressedString) {
        if (isdigit(letter)) {
            repetition *= 10;
            repetition += getIntFromChar(letter);
        }
        else {
            if (repetition == 0) {
                decompressedString.push_back(letter);
            }
            else {
                const std::string multipleLetters(repetition, letter);
                decompressedString.append(multipleLetters);
            }

            repetition = 0;
        }
    }

    return decompressedString;
}

int main() {
    const std::string compressedString = readInput();
    const std::string decompressedString = decompres(compressedString);

    std::cout << decompressedString << std::endl;

    return 0;
}
