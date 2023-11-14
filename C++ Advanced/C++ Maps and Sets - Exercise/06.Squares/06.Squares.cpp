#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

void readInput(std::vector<int>& numbers) {
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    double num = 0.0;

    while (istr >> num) {
        numbers.push_back(num);
    }
}

bool isSquare(int& num) {
    if (num < 0)
        return false;

    int sqRoot = sqrt(num);
    if ((sqRoot * sqRoot) == num)
        return true;

    return false;
}

std::vector<int> AddSquareNumbers(std::vector<int>& numbers) {
    std::vector<int> squareNumbers;

    for (auto num : numbers) {

        if (isSquare(num)) {
            squareNumbers.push_back(num);
        }
    }

    return squareNumbers;
}

void printSolution(std::vector<int>& squareNumbers) {
    sort(squareNumbers.begin(), squareNumbers.end(), std::greater<int>());

    for (auto i = 0; i < squareNumbers.size(); ++i) {
        std::cout << squareNumbers[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;
    readInput(numbers);

    std::vector<int> squareNumbers = AddSquareNumbers(numbers);

    printSolution(squareNumbers);

    return 0;
}

// -----------------------------------------------------------------------------------------
// Decision with set 80/100 points.

// #include <iostream>
// #include <set>
// #include <string>
// #include <sstream>
// #include <cmath>

// void readInput(std::set<int>& numbers) {
//     std::string line;
//     getline(std::cin, line);

//     std::istringstream istr(line);

//     double num = 0.0;

//     while (istr >> num) {
//         numbers.insert(num);
//     }
// }

// bool isSquare(int& num) {
//     if (num < 0)
//         return false;

//     int sqRoot = sqrt(num);
//     if ((sqRoot * sqRoot) == num)
//         return true;

//     return false;
// }

// std::set<int> AddSquareNumbers(std::set<int>& numbers) {
//     std::set<int> squareNumbers;

//     for (auto num : numbers) {

//         if (isSquare(num)) {
//             squareNumbers.insert(num);
//         }
//     }

//     return squareNumbers;
// }

// void printSolution(std::set<int>& squareNumbers) {
//     for (auto i = squareNumbers.rbegin(); i != squareNumbers.rend(); ++i) {
//         std::cout << *i << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::set<int> numbers;
//     readInput(numbers);

//    std::set<int> squareNumbers = AddSquareNumbers(numbers);

//     printSolution(squareNumbers);

//     return 0;
// }
