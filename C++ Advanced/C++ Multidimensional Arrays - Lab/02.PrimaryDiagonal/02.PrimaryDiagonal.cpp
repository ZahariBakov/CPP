#include <iostream>
#include <vector>

std::vector<std::vector<int>> createMatrixFromInput() {
    int rows = 0;
    std::cin >> rows;

    std::vector<std::vector<int>> matrix(rows);

    for (int row = 0; row < rows; ++row) {
        matrix[row].resize(rows);

        for (int col = 0; col < rows; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    return matrix;
}

int sumPrimaryDiagonal(std::vector<std::vector<int>>& matrix) {
    int result = 0;
    size_t size = matrix.size();

    for (auto row = 0; row < size; ++row) {
        for (auto col = 0; col < size; ++col) {
            if (row == col) {
                result += matrix[row][col];
            }
        }
    }

    return result;
}

int main() {
    auto matrix = createMatrixFromInput();
    int result = sumPrimaryDiagonal(matrix);

    std::cout << result << std::endl;

    return 0;
}


//3
//11 2 4
//4 5 6
//10 8 -12