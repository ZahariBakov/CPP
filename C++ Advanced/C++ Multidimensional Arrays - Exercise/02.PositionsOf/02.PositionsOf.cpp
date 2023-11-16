#include <iostream>
#include <vector>

std::vector<std::vector<int>> readVec2DFromInput() {
    int rows = 0;
    int cols = 0;
    std::cin >> rows >> cols;

    std::vector<std::vector<int>> vec2D(rows);

    for (int row = 0; row < rows; ++row) {
        vec2D[row].resize(cols);

        for (int col = 0; col < cols; ++col) {
            std::cin >> vec2D[row][col];
        }
    }

    return vec2D;
}

void printSearchedNum(int num, const std::vector<std::vector<int>>& vec2D) {
    bool found = false;

    for (int row = 0; row < vec2D.size(); ++row) {
        for (int col = 0; col < vec2D[row].size(); ++col) {
            if (num == vec2D[row][col]) {
                std::cout << row << " " << col << std::endl;
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "not found" << std::endl;
    }
}

int main() {
    const auto vec2D = readVec2DFromInput();
    int searchedNum = 0;
    std::cin >> searchedNum;
    printSearchedNum(searchedNum, vec2D);

    return 0;
}
