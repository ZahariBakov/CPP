#include <iostream>

void readCharArray2DFromInput(char**& charArr2D, int& rows, int& cols) {
    std::cin >> rows >> cols;
    charArr2D = new char*[rows] {};

    for (int i = 0; i < rows; ++i) {
        charArr2D[i] = new char[cols] {};

        for (int j = 0; j < cols; ++j) {
            std::cin >> charArr2D[i][j];
        }
    }
}

void allocateIntArray2D(int**& intArr2D, int rows, int cols) {
    intArr2D = new int* [rows] {};

    for (int i = 0; i < rows; ++i) {
        intArr2D[i] = new int[cols] {};
    }
}

void releaseMemoryForChar2DArray(char**& charArr2D, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] charArr2D[i];
        charArr2D[i] = nullptr;
    }

    delete[] charArr2D;
    charArr2D = nullptr;
}

void releaseMemoryForInt2DArray(int**& intArr2D, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] intArr2D[i];
        intArr2D[i] = nullptr;
    }

    delete[] intArr2D;
    intArr2D = nullptr;
}

void printArrayChar2D(char** charArr2D, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << charArr2D[i][j];
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printArrayInt2D(int** intArr2D, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << intArr2D[i][j];
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isInBoundary(int rows, int cols, int currRow, int currCol) {
    if (0 > currRow || 0 > currCol) {
        return false;
    }

    if (currRow >= rows || currCol >= cols) {
        return false;
    }

    return true;
}

void expandMine(int** intArr2D, int rows, int cols, int currRow, int currCol) {
    const int dirCount = 9;
    const int directions[dirCount][2]{
        { 0, 0}, // current position
        { 0, 1}, // right
        { 1, 1}, // down right
        { 1, 0}, // down 
        { 1, -1}, // down left
        { 0, -1}, // left 
        { -1, -1}, // up left
        { -1, 0}, // up 
        { -1, 1}, // up right
    };

    for (int i = 0; i < dirCount; ++i) {
        const int newRow = currRow + directions[i][0];
        const int newCol = currCol + directions[i][1];

        const bool isInBound = isInBoundary(rows, cols, newRow, newCol);
        if (isInBound) {
            intArr2D[newRow][newCol]++;
        }
    }
}

void processMines(char** charArr2D, int rows, int cols,
                  int** intArr2D) {
    const char mineMarker = '!';

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (charArr2D[row][col] != mineMarker) {
                continue;
            }

            expandMine(intArr2D, rows, cols, row, col); 
        }
    }
}

int main() {
    int rows = 0;
    int cols = 0;
    char** charArr2D = nullptr;
    int** intArr2D = nullptr;

    readCharArray2DFromInput(charArr2D, rows, cols);
    allocateIntArray2D(intArr2D, rows, cols);

    processMines(charArr2D, rows, cols, intArr2D);

    // printArrayChar2D(charArr2D, rows, cols);
    printArrayInt2D(intArr2D, rows, cols);

    releaseMemoryForChar2DArray(charArr2D, rows);
    releaseMemoryForInt2DArray(intArr2D, rows);

    return 0;
}
