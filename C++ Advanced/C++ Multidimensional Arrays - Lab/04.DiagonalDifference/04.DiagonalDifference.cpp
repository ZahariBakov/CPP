#include <iostream>
#include <vector>

std::vector<std::vector<int>> createMatrixFromInput() {
    int size = 0;
    std::cin >> size;

    std::vector<std::vector<int>> matrix(size);

    for (int row = 0; row < size; ++row) {
        matrix[row].resize(size);

        for (int col = 0; col < size; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    return matrix;
}

void sumDiagonals(std::vector<std::vector<int>>& matrix, int& primarySum, int& secondarySum) {
    int size = matrix.size();

    for (auto row = 0; row < size; ++row) {
        for (auto col = 0; col < size; ++col) {
            if (row == col) {
                primarySum += matrix[row][col];
            }
        }
        secondarySum += matrix[row][size - row - 1];
    }
}

void printSolution(int& primarySum, int& secondarySum) {
    int diff = abs(primarySum - secondarySum);

    std::cout << diff << std::endl;
}

int main() {
    auto matrix = createMatrixFromInput();
    int primarySum = 0; 
    int secondarySum = 0;
    sumDiagonals(matrix, primarySum, secondarySum);
    printSolution(primarySum, secondarySum);

    return 0;
}
