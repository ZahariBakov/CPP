#include <iostream>
#include <vector>

std::vector<std::vector<int>> createVec2D(int rows, int cols) {
    std::vector<std::vector<int>> vec2D(rows, std::vector<int>(cols));

    return vec2D;
}

void increaseAllElementByCopy(std::vector<std::vector<int>> vec2D,
                              int incrValue) {
    for (auto& row : vec2D) {
        for (auto& elem : row) {
            elem += incrValue;
        }
    } 
}

void increaseAllElementNoCopy(std::vector<std::vector<int>>& vec2D,
                              int incrValue) {
    for (auto& row : vec2D) {
        for (auto& elem : row) {
            elem += incrValue;
        }
    }
}

void print(const std::vector<std::vector<int>>& vec2D) {
    for (const auto& row : vec2D) {
        for (const auto elem : row) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    const int rows = 3;
    const int cols = 5;
    auto vec2D = createVec2D(rows, cols);

    increaseAllElementByCopy(vec2D, 1);
    print(vec2D);

    increaseAllElementNoCopy(vec2D, 1);
    print(vec2D);

    return 0;
}
