#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void readInput(int& width, int& height, std::string& msg) {
    std::cin >> width;
    std::cin.ignore();

    std::cin >> height;
    std::cin.ignore();

    getline(std::cin, msg);
}

std::vector<std::string> readAlphabet(int height) {
    std::vector<std::string> alphabet(height);

    for (int i = 0; i < height; i++) {
        getline(std::cin, alphabet[i]);
    }

    return alphabet;
}

void printHelper(const std::vector<std::string>& alphabet) {
    for (const std::string& elem : alphabet) {
        std::cerr << elem << std::endl;
    }
}

int getAlphabetIndex(char c) {
    c = toupper(c);

    if (isalpha(c)) {
        const int index = c - 'A';
        return index;
    }

    const int nonAlphaIndex = 26;
    return nonAlphaIndex;
}

std::vector<int> getMsgIndexArr(const std::string& msg) {
    const size_t msgSize = msg.size();
    std::vector<int> arr(msgSize);

    for (size_t i = 0; i < msgSize; i++) {
        arr[i] = getAlphabetIndex(msg[i]);
    }

    return arr;
}

void printSolution(const std::vector<std::string>& alphabet,
                   const std::string& msg,
                   int letterWidth) {
    const std::vector<int> msgIndexes = getMsgIndexArr(msg);
    const size_t alphabetHeight = alphabet.size();

    for (size_t i = 0; i < alphabetHeight; ++i) {
        for (const int index : msgIndexes) {
            std::cout << alphabet[i].substr(index * letterWidth, letterWidth);
        }
        std::cout << std::endl;
    }
}

int main() {
    int width = 0;
    int height = 0;
    std::string msg;

    readInput(width, height, msg);

    const std::vector<std::string> alphabet = readAlphabet(height);

    printSolution(alphabet, msg, width);

    return 0;
}