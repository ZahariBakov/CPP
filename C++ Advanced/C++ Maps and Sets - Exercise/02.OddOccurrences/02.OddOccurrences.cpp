#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

void readInput(std::vector<std::string>& words) {
    std::string currWord;
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    while (istr >> currWord) {
        words.push_back(currWord);
    }
}

char toLower(char inputChar) {
    return toLower(inputChar);
}

void transformToLowerCase(std::vector<std::string>& words) {
    for (auto& word : words) {
        std::transform(word.begin(), word.end(), word.begin(), tolower);
    }
}

std::unordered_map<std::string, int> produceCountMap(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> countMap;

    for (const auto& word : words) {
        countMap[word]++;
    }

    return countMap;
}

std::vector<std::string> produceAnswerWords(
        const std::unordered_map<std::string, int>& countMap,
        const std::vector<std::string>& inputWords) {
    std::vector<std::string> answerWords;
    std::unordered_set<std::string> uniquesWordsWithOddCount;

    for (const auto& word : inputWords) {
        auto it = countMap.find(word);

        if (it == countMap.end()) {
            std::cerr << "Did not find word: " << word << " in the countMap." << std::endl;
            continue;
        }

        // const bool hasOddCount = it->second % 2 == 0;
        const bool hasOddCount = it->second & 1;

        if (hasOddCount) {
            if (uniquesWordsWithOddCount.find(it->first) == uniquesWordsWithOddCount.end()) {
                uniquesWordsWithOddCount.insert(it->first);
                answerWords.push_back(it->first);
            }
        }
    }

    return answerWords;
}

void printSolution(const std::vector<std::string>& answerWords) {
    std::ostringstream ostr;

    for (const auto& word : answerWords) {
        ostr << word << ", ";
    }

    std::string result = ostr.str();

    if (!result.empty()) {
        result.pop_back();
        result.pop_back();
    }

    std::cout << result << std::endl;
}

int main() {
    std::vector<std::string> words;
    readInput(words);
    transformToLowerCase(words);
    const auto countMap = produceCountMap(words);

    const auto answerWords = produceAnswerWords(countMap, words);
    printSolution(answerWords);

    return 0;
}
