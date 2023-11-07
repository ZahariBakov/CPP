#include <iostream>
#include <set>
#include <string>
#include <list>

std::list<std::string> readInput() {
    std::set<std::string> names;
    std::list<std::string> uniqueNames;
    int numberOfNames;
    std::cin >> numberOfNames;
    std::string name;

    for (int i = 0; i < numberOfNames; ++i) {
        std::cin >> name;
        
        if (names.find(name) == names.end()) {
            names.insert(name);
            uniqueNames.push_back(name);
        }
    }

    return uniqueNames;
}

void printSolution(std::list<std::string>& uniqueNames) {
    for (std::string name : uniqueNames) {
        std::cout << name << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::list<std::string> uniqueNames = readInput();

    printSolution(uniqueNames);

    return 0;
}
