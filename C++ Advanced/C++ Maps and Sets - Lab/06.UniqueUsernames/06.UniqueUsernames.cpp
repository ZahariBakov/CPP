#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> readInput() {
    int n;
    std::cin >> n;

    std::map<std::string, int> names;
    std::vector<std::string> uniqueNames;
    std::string input;

    for (int i = 0; i < n; ++i) {
        std::cin >> input;

        std::map<std::string, int> ::iterator it = names.find(input);

        if (it == names.end()) {
            uniqueNames.push_back(input);
        }

        names[input]++;
    }

    return uniqueNames;
}

void printSolutin(const std::vector<std::string>& uniqueNames) {
     for (std::string elem : uniqueNames) {
         std::cout << elem << std::endl;
     }
}

int main() {
    std::vector<std::string> uniqueNames = readInput();

    std::cout << std::endl;

    printSolutin(uniqueNames);

    return 0;
}
