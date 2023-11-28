#include <iostream>
#include <string>
#include <map>
#include <vector>

typedef std::string TenStrings[10];

void printArray(TenStrings strings) {
    for (int i = 0; i < 10; ++i) {
        std::cout << strings[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    typedef unsigned long long ull;
    ull number = 42; // unsigned long long number = 42;

    TenStrings words = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "!" };

    printArray(words);

    std::cout << std::endl;

    typedef std::map<std::string, std::vector<int>> StudentsScore;

    // We can also use "using". It is similar to "typedef".
    using Scores = std::map<std::string, std::vector<int>>;

    StudentsScore assignment2Scores;
    assignment2Scores["ghost4e"] = { 100, 100, 100, 100 };
    assignment2Scores["Reclaimer"] = { 100, 80, 0, 100 };
    assignment2Scores["SpecificDude"] = { 100, 90, 100, 100 };

    for (StudentsScore::iterator it = assignment2Scores.begin(); it != assignment2Scores.end(); ++it) {
        std::cout << it->first << " ";

        for (int score : it->second) {
            std::cout << score << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
