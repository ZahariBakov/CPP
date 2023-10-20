#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> readInput() {
    std::vector<std::string> vec;
    const std::string delimiter = "hot-potatoes";
    std::string word;
    std::cin >> word;

    while (word != delimiter) {
        vec.push_back(word);
        std::cin >> word;
    }

    return vec;
}

void printInReverseOrder(std::vector<std::string>& words) {
    for (int i = words.size() - 1; i >= 0; --i) {
        std::cout << words[i] << ' ';
    }
}

int main() {
    std::vector<std::string> words = readInput();
    printInReverseOrder(words);

    return 0;
}

// input:
// Hello C++ Dudes hot-potatoes

// output:
// Dudes C++ Hello
