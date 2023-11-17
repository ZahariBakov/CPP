#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> createMatrixFromInput() {
    int rows = 0;
    int cols = 0;
    std::cin >> rows >> cols;

    std::string word;
    std::cin >> word;

    std::vector<std::vector<char>> matrix(rows);
    int idx = 0;

    for (int i = 0; i < rows; ++i) {
        std::vector<char> rowElements(cols);

        if (i % 2 == 0) {
            for (int j = 0; j < cols; ++j) {
                rowElements[j] = word[idx % word.length()];
                idx++;
            }
        }
        else {
            for (int j = cols - 1; j > -1; --j) {
                rowElements[j] = word[idx % word.length()];
                idx++;
            }
        }

        matrix[i] = rowElements;
    }

    return matrix;
}

void printSolution(const std::vector<std::vector<char>>& matrix) {
    for (auto& row : matrix) {
        for (auto& elem : row) {
            std::cout << elem;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int main() {
    const auto matrix = createMatrixFromInput();
    printSolution(matrix);

    return 0;
}
