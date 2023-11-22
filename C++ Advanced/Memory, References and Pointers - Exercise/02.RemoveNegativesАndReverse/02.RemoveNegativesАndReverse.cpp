#include <iostream>
#include <string>
#include <sstream>

void readInput(int*& arr, int& size) {
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    const size_t maxSize = (line.size() / 2) + 1;
    arr = new int[maxSize] {};

    int currNumber = 0;
    while (istr >> currNumber) {
        arr[size] = currNumber;
        ++size;
    }
}

void releaseMemory(int*& arr) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

void getPositiveNumberFromArray(int*& arr, int*& positiveArr, int arrSize, int& positiveArrSize) {
    int currNumber = 0;
    for (int i = 0; i < arrSize; ++i) {
        currNumber = arr[i];

        if (currNumber >= 0) {
            positiveArr[positiveArrSize] = currNumber;
            positiveArrSize++;
        }
    }
}

void reverseNumbersInArray(int* positiveArr, int* positiveReverseArr, int size) {
    int currIdxToGet = 0;

    for (int i = 0; i < size; ++i) {
        currIdxToGet = (size - 1) - i;

        positiveReverseArr[i] = positiveArr[currIdxToGet];
    }
}

void printNumbers(int* positiveReverseArr, int size) {
    if (size == 0) {
        std::cout << "empty" << std::endl;
    }
    else {
        for (int i = 0; i < size; ++i) {
            std::cout << positiveReverseArr[i] << " ";
        }
    }

    std::cout << std::endl;
}

int main() {
    int* arr = nullptr;
    int arrSize = 0;
    readInput(arr, arrSize);

    int* positiveArr = new int[arrSize] {};
    int positiveArrSize = 0;

    getPositiveNumberFromArray(arr, positiveArr, arrSize, positiveArrSize);

    int* positiveReverseArr = new int[positiveArrSize] {};

    reverseNumbersInArray(positiveArr, positiveReverseArr, positiveArrSize);

    printNumbers(positiveReverseArr, positiveArrSize);

    releaseMemory(positiveReverseArr);
    releaseMemory(positiveArr);
    releaseMemory(arr);

    return 0;
}
