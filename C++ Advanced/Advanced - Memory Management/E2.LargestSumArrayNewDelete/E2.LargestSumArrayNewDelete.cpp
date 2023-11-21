#include <iostream>
#include <utility>

/*test input*/
//3
//4  1 5 2 11
//2  10 42
//5  1 -2 3 0 -3

/*test output*/
// 10 42

std::pair<int**, int*> readInput(int& rows) {
    std::cin >> rows;
    int** arr2D = new int* [rows] {};
    int* arr1DSizes = new int[rows] {};

    for (int i = 0; i < rows; ++i) {
        int currArrSize = 0;
        std::cin >> currArrSize;
        arr1DSizes[i] = currArrSize;
        arr2D[i] = new int[currArrSize] {};

        for (int j = 0; j < currArrSize; ++j) {
            std::cin >> arr2D[i][j];
        }
    }

    return std::make_pair(arr2D, arr1DSizes);
}

void releaseMemory(std::pair<int**, int*>& arrayInfo, int rows) {
    int** arr2D = arrayInfo.first;
    int* arr1DSizes = arrayInfo.second;

    delete[] arr1DSizes;
    arr1DSizes = nullptr;

    for (int i = 0; i < rows; ++i) {
        delete[] arr2D[i];
        arr2D[i] = nullptr;
    }

    delete[] arr2D;
    arr2D = nullptr;
}

std::pair<int*, int> findMaxArr(const std::pair<int**, int*>& arrayInfo, int rows) {
    int* maxArr = nullptr;
    int maxArrSize = 0;
    int maxSum = std::numeric_limits<int>::min();

    int** arr2D = arrayInfo.first;
    int* arr1DSizes = arrayInfo.second;

    for (int i = 0; i < rows; ++i) {
        int localSum = 0;
        const int currArrSize = arr1DSizes[i];

        for (int j = 0; j < currArrSize; ++j) {
            localSum += arr2D[i][j];
        }

        if (localSum > maxSum) {
            maxSum = localSum;
            maxArr = arr2D[i];
            maxArrSize = currArrSize;
        }
    }

    return std::make_pair(maxArr, maxArrSize);
}

void printMaxArray(const std::pair<int*, int>& maxArray) {
    const int* arr = maxArray.first;
    const int size = maxArray.second;

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int rows = 0;
    std::pair<int**, int*> arrayInfo = readInput(rows);
    std::pair<int*, int> maxArray = findMaxArr(arrayInfo, rows);

    printMaxArray(maxArray);

    releaseMemory(arrayInfo, rows);

    return 0;
}
