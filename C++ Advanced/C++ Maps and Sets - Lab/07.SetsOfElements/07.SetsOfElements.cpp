#include <iostream>
#include <set>
#include <vector>

void readNumberToSet(int num, std::set<int>& NumbersSet, std::vector<int>& orderSet) {
    for (int i = 0; i < num; ++i) {
        int num;
        std::cin >> num;

        auto it = find(NumbersSet.begin(), NumbersSet.end(), num);

        if (it == NumbersSet.end()) {
            NumbersSet.insert(num);
            orderSet.push_back(num);
        }
    }
}

std::vector<int> uniqueSet(std::vector<int>& orderFirst, std::vector<int>& orderSecond) {
    std::vector<int> uniqueElem;

    for (auto firstNum : orderFirst) {
        for (auto secondNum : orderSecond) {
            if (firstNum == secondNum) {
                uniqueElem.push_back(firstNum);
            }
        }
    }

    return uniqueElem;
}

void printSolution(std::vector<int>& uniqueElem) {

    for (auto num : uniqueElem) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int firstSetLength;
    int secondSetLength;

    std::cin >> firstSetLength >> secondSetLength;

    std::set<int> firstNumbersSet;
    std::vector<int> orderFirst;
    readNumberToSet(firstSetLength, firstNumbersSet, orderFirst);


    std::set<int> secodnNumbersSet;
    std::vector<int> orderSecond;
    readNumberToSet(secondSetLength, secodnNumbersSet, orderSecond);

    std::vector<int> uniqueElem = uniqueSet(orderFirst, orderSecond);

    std::cout << std::endl;

    printSolution(uniqueElem);

    return 0;
}
