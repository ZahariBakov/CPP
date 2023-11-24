#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

void readInput(std::vector<std::string>& words) {
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    std::string currWord;

    while (istr >> currWord) {
        currWord.erase(remove(currWord.begin(), currWord.end(), '.'), currWord.end());
        currWord.erase(remove(currWord.begin(), currWord.end(), ','), currWord.end());
        currWord.erase(remove(currWord.begin(), currWord.end(), '!'), currWord.end());
        currWord.erase(remove(currWord.begin(), currWord.end(), '?'), currWord.end());
        words.push_back(currWord);
    }
}

char toLowerChar(char inputChar) {
    return tolower(inputChar);
}

void toLowerString(std::string& extension) {
    std::transform(extension.begin(), extension.end(), extension.begin(), toLowerChar);
}

void printFoundWord(const std::set<std::string> foundWords) {
    if (foundWords.empty()) {
        std::cout << "---" << std::endl;
    }
    else {
        for (const auto word : foundWords) {
            std::cout << word << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> words;
    readInput(words); 

    while (true) {
        char letter;
        std::cin >> letter;

        if (letter == '.') {
            break;
        }

        std::set<std::string> foundWords;
        for (auto word : words) {
            auto wordToLower = word;
            toLowerString(wordToLower);
            size_t position = wordToLower.find(tolower(letter));

            if (position != std::string::npos) {
                foundWords.insert(word);
            }
        }

        printFoundWord(foundWords);
    }

    return 0;
}
