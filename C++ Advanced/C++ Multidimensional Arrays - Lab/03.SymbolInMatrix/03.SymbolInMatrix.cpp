#include <iostream>
#include <string>
#include <vector>

void createMatrixfromInput(std::vector<std::vector<char> >& matrix) {
    int size = 0;
    std::cin >> size;
    matrix.resize(size);

    for (int row = 0; row < size; ++row) {
        matrix[row].resize(size);

        for (int col = 0; col < size; ++col) {
            std::cin >> matrix[row][col];
        }
    }
}

int main() {
    std::vector<std::vector<char> > matrix;
    createMatrixfromInput(matrix);

    char searchedSymbol;
    std::cin >> searchedSymbol;

    int size = matrix.size();

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (matrix[row][col] == searchedSymbol) {
                std::cout << "(" << row << ", " << col << ")";
                return 0;
            }
        }
    }

    std::cout << searchedSymbol << " does not occur in the matrix";
    return 0;
}
