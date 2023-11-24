#include <iostream>
#include <string>
#include <sstream>

void readArray2DFromInput(int**& arr2D, int& rows, int& cols) {
    std::cin >> rows;
    std::cin.ignore();

    arr2D = new int* [rows] {};

    for (int i = 0; i < rows; ++i) {
        arr2D[i] = new int[10] {};

        std::string line;
        getline(std::cin, line);

        std::istringstream istr(line);

        cols = 0;
        while (istr >> arr2D[i][cols]) {
            cols++;
        }
    }
}

void releaseMemory(int**& arr2D, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr2D[i];
        arr2D[i] = nullptr;
    }

    delete[] arr2D;
    arr2D = nullptr;
}

bool compareArrays(int**& firstArr2D, int firstArrRows, int firstArrCols,
                   int**& secondArr2D, int secondArrRows, int secodnArrCols) {
    if (firstArrRows != secondArrRows || firstArrCols != secodnArrCols) {
        return false;
    }

    for (int row = 0; row < firstArrRows; ++row) {
        for (int col = 0; col < firstArrCols; ++col) {
            if (firstArr2D[row][col] != secondArr2D[row][col]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int firstArrRows = 0;
    int firstArrCols = 0;
    int** firstArr2D = nullptr;
    readArray2DFromInput(firstArr2D, firstArrRows, firstArrCols);

    int secondArrRows = 0;
    int secodnArrCols = 0;
    int** secondArr2D = nullptr;
    readArray2DFromInput(secondArr2D, secondArrRows, secodnArrCols);

    bool isEqual = compareArrays(firstArr2D, firstArrRows, firstArrCols, secondArr2D, secondArrRows, secodnArrCols);

    std::cout << (isEqual ? "equal" : "not equal") << std::endl;

    releaseMemory(firstArr2D, firstArrRows);
    releaseMemory(secondArr2D, secondArrRows);

    return 0;
}
