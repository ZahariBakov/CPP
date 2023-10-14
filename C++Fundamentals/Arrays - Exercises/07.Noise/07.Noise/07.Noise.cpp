#include <iostream>
#include <array>
#include <cctype>
#include <cmath>

const int maxSize = 1000;

std::array<char, maxSize> readInput(int& actualArrSize) {
    std::array<char, maxSize> arr{};
    actualArrSize = 0;

    char c = ' ';

    while (true) {
        std::cin >> c;

        if (c == '.') {
            break;
        }

        arr[actualArrSize] = c;
        actualArrSize++;
    }

    if (actualArrSize >= maxSize) {
        std::cout << "Error!" << std::endl;
    }

    return arr;
}

int getIntFromChar(char c) {
    return c - '0';
}

void appendDigitToNumber(char digit, int& num) {
    num *= 10;
    num += getIntFromChar(digit);
}

// 25.
// ,,-2!!as**dsa5*-.

int main()
{
    int arrSize = 0;
    const std::array<char, maxSize> arr = readInput(arrSize);

    int result = 0;

    for (int i = 0; i < arrSize; i++) {
        if (isdigit(arr[i])) {
            appendDigitToNumber(arr[i], result);
        }
    }
    std::cout << sqrt(result) << std::endl;

    return 0;
}
