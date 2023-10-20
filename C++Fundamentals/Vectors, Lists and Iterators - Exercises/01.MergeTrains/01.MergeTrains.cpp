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
    while (!words.empty()) {
        std::cout << words.back() << ' ';
        words.pop_back();
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
