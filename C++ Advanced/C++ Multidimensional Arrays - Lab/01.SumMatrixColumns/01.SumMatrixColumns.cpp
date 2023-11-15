#include <iostream>
#include <vector>

void readInput(int& rows, int& cols, std::vector<std::vector<int>>& matrix) {
    std::cin >> rows >> cols;

    matrix.resize(rows);

    for (int row = 0; row < rows; ++row) {
        matrix[row].resize(cols);

        for (int col = 0; col < cols; ++col) {
            std::cin >> matrix[row][col];
        }
    }
}

std::vector<int> sumColumns(int rows, int cols, std::vector<std::vector<int>>& matrix) {
    std::vector<int> columnsSum;

    for (int col = 0; col < cols; ++col) {
        int currentColSum = 0;

        for (int row = 0; row < rows; ++row) {
            currentColSum += matrix[row][col];
        }

        columnsSum.push_back(currentColSum);
    }

    return columnsSum;
}

void printSolution(std::vector<int>& columnsSum) {
    for (auto& elem : columnsSum) {
        std::cout << elem << std::endl;
    }
}

//void printMatrix(std::vector<std::vector<int>>& matrix) {
//    for (auto row : matrix) {
//        for (auto elem : row) {
//            std::cout << elem << " ";
//        }
//        std::cout << std::endl;
//    }
//}

int main() {
    std::vector<std::vector<int>> matrix;
    int rows = 0;
    int cols = 0; 
    readInput(rows, cols, matrix);

    std::vector<int> columsSum = sumColumns(rows, cols, matrix);

    printSolution(columsSum);

    /*std::cout << std::endl;
    printMatrix(matrix);*/


    return 0;
}
