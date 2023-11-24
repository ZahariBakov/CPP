#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>

void readInput(char*& sentence, size_t& size) {
    int n = 125;
    sentence = new char[n];

    std::cin.get(sentence, n);

    size = strlen(sentence);
}

void releaseMemory(char*& sentence) {
    if (sentence != nullptr) {
        delete[] sentence;
        sentence = nullptr;
    }
}

void toLowerSentence(char*& sentence, size_t& size) {
    for (size_t i = 0; i < size; ++i) {
        sentence[i] = tolower(sentence[i]);
    }
}

void toUpperSentence(char*& sentence, size_t& size) {
    for (size_t i = 0; i < size; ++i) {
        sentence[i] = toupper(sentence[i]);
    }
}

int main() {
    char* sentence = nullptr;
    size_t size;
    readInput(sentence, size);

    toLowerSentence(sentence, size);
    std::cout << sentence << std::endl;

    toUpperSentence(sentence, size);
    std::cout << sentence << std::endl;

    releaseMemory(sentence);

    return 0;
}
