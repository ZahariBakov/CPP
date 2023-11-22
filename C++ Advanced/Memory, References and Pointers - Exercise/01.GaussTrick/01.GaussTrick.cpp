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

void sumElements(int* inputArr, int inputSize,
                     int* resultArr, int resultSize) {
    int endIndex = 0;
    for (int i = 0; i < resultSize; ++i) {
        endIndex = inputSize - 1 - i;
        if (i != endIndex) {
            resultArr[i] = inputArr[i] + inputArr[endIndex];
        }
        else {
            resultArr[i] = inputArr[i];
        }
    }
}

void printElements(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int* arr = nullptr;
    int arrSize = 0;
    readInput(arr, arrSize);

    int halfArrSize = arrSize / 2;
    if (arrSize & 1) { // odd
        halfArrSize += 1;
    }
    int* resultArr = new int[halfArrSize] {};

    sumElements(arr, arrSize, resultArr, halfArrSize);

    printElements(resultArr, halfArrSize);

    releaseMemory(resultArr);
    releaseMemory(arr);

    return 0;
}
