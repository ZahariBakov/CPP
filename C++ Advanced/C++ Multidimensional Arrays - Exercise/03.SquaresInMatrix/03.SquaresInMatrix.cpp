#include <iostream>
#include <vector>

std::vector<std::vector<char>> readMatrixFromInput() {
    int rows = 0;
    int cols = 0;
    std::cin >> rows >> cols;

    std::vector<std::vector<char>> matrix(rows);
    
    for (int row = 0; row < rows; ++row) {
        matrix[row].resize(cols);

        for (int col = 0; col < cols; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    return matrix;
}

int findSquaresInMatrix(const std::vector<std::vector<char>>& matrix) {
    int result = 0;
    int rowSize = int(matrix.size());
    int colSize = int(matrix[0].size());
    char searchedChar;

    for (int row = 0; row < rowSize - 1; ++row) {
        for (int col = 0; col < colSize - 1; ++col) {
            searchedChar = matrix[row][col];
            if (searchedChar == matrix[row + 1][col]) {
                if (searchedChar == matrix[row][col + 1]) {
                    if (searchedChar == matrix[row + 1][col + 1]) {
                        result += 1;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    const auto matrix = readMatrixFromInput();
    int findSquares = findSquaresInMatrix(matrix);

    std::cout << findSquares << std::endl;

    return 0;
}
