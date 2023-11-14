#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

char toLower(char inputChar) {
    return toLower(inputChar);
}

void readInputAndAddToSetInLowercase(std::set<std::string>& words) {
    std::string currWord;
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    while (istr >> currWord) {
        std::transform(currWord.begin(), currWord.end(), currWord.begin(), tolower);
        words.insert(currWord);
    }
}

void addShortestWords(const std::set<std::string>& words, std::set<std::string>& lessThan5CharactersWords) {
    for (auto word : words) {
        
        if (word.size() < 5) {
            lessThan5CharactersWords.insert(word);
        }
        
    }
}

void printSolution(std::set<std::string>& lessThan5CharactersWords) {
    for (auto i = lessThan5CharactersWords.begin(); i != lessThan5CharactersWords.end(); ++i) {
        std::cout << *i << (i != --lessThan5CharactersWords.end() ? ", " : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> words;
    readInputAndAddToSetInLowercase(words); 

    std::set<std::string> lessThan5CharactersWords;
    addShortestWords(words, lessThan5CharactersWords);

    printSolution(lessThan5CharactersWords);

    return 0;
}
