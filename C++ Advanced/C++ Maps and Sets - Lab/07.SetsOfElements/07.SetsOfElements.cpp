#include <iostream>
#include <set>
#include <vector>

std::set<int> readNumberToSet(int num) {
    std::set<int> sets;
    int currentNum;

    for (int i = 0; i < num; ++i) {
        std::cin >> currentNum;
        sets.insert(currentNum);
    }

    return sets;
}

std::vector<int> getUniqueElem(std::set<int>& BigestSet, std::set<int>& LowerSet) {
    std::vector<int> uniqueElem;

    for (auto& firstElem : BigestSet) {
        for (auto& secondElem : LowerSet) {
            if (firstElem == secondElem) {
                uniqueElem.push_back(firstElem);
            }
        }
    }

    return uniqueElem;
}

std::vector<int> findBiggestSet(std::set<int>& firstNumberSet, std::set<int>& secodnNumberSet) {
    std::vector<int> uniqueElem;

    if (firstNumberSet.size() > secodnNumberSet.size()) {
        uniqueElem = getUniqueElem(firstNumberSet, secodnNumberSet);
    }
    else {
        uniqueElem = getUniqueElem(secodnNumberSet, firstNumberSet);
    }

    return uniqueElem;
}

void printSolution(std::vector<int>& uniqueElem) {
    for (int i = 0; i < uniqueElem.size(); ++i) {
        std::cout << uniqueElem[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int firstSetLength;
    int secondSetLength;

    std::cin >> firstSetLength >> secondSetLength;

    std::set<int> firstNumberSet = readNumberToSet(firstSetLength);
    std::set<int> secodnNumberSet = readNumberToSet(secondSetLength);

    std::vector<int> uniqueElem = findBiggestSet(firstNumberSet, secodnNumberSet);

    std::cout << std::endl;

    printSolution(uniqueElem);

    return 0;
}
