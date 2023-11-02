#include <iostream>
#include <array>

const int rows = 3;
const int cols = 5;

void increaseAllElementByCopy(std::array<std::array<int, cols>, rows> arr,
    int incrValue) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] += incrValue;
        }
    }
}

void increaseAllElementNoCopy(std::array<std::array<int, cols>, rows>& arr,
    int incrValue) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] += incrValue;
        }
    }
}

void printArray(const std::array<std::array<int, cols>, rows>& arr) {
    // These are three examples are the same. The different between them is the syntax.

    /*for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }*/

    /*for (const std::array<int, cols>& row : arr) {
        for (const int elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }*/

    for (const auto& row : arr) {
        for (const auto elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::array<std::array<int, cols>, rows> arr{ }; // zero initializer

    increaseAllElementByCopy(arr, 1);
    printArray(arr);

    increaseAllElementNoCopy(arr, 1);
    printArray(arr);

    return 0;
}
