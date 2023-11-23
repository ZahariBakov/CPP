#include <iostream>
#include <string>
#include <sstream>

void readArray2DFromInput(int**& arr2D, int& rows, int& cols) {
    std::cin >> rows >> cols;
    arr2D = new int*[rows] {};

    for (int i = 0; i < rows; ++i) {
        arr2D[i] = new int[cols] {};

        for (int j = 0; j < cols; ++j) {
            std::cin >> arr2D[i][j];
        }
    }

}

void printArra2D(int**& arr2D, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr2D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void releaseMemory(int**& arr2D, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr2D[i];
        arr2D[i] = nullptr;
    }

    delete[] arr2D;
    arr2D = nullptr;
}

int main() {
    int** arr2D = nullptr;
    int rows = 0;
    int cols = 0;
    readArray2DFromInput(arr2D, rows, cols);

    int endRows = 0;
    int endCols = 0;
    std::cin >> endRows >> endCols;

    printArra2D(arr2D, endRows, endCols);

    releaseMemory(arr2D, rows);

    return 0;
}
