#include <iostream>
#include <array>
#include <queue>

const int size = 10;

std::array<std::array<char, size>, size> ReadMatrixFromInput() {
    std::array<std::array<char, size>, size> matrix;

    for (auto& row : matrix) {
        for (auto& element : row) {
            std::cin >> element;
        }
    }

    return matrix;
}

int readTurnsFromInput() {
    int turns = 0;
    std::cin >> turns;

    return turns;
}

std::queue<std::pair<int, int>> getInitialRustTiles(const std::array<std::array<char, size>, size>& matrix) {
    std::queue<std::pair<int, int>> rustTiles;


    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (matrix[row][col] == '!') {
                rustTiles.push(std::make_pair(row, col));
            }
        }
    }

    return rustTiles;
}

bool isInBounds(int currRowIdx, int currColIdx) {
    if (currRowIdx < 0 || currColIdx < 0) {
        return false;
    }

    if (currRowIdx >= size || currColIdx >= size) {
        return false;
    }

    return true;
}

void processSingleTurn(std::array<std::array<char, size>, size>& matrix,
                       std::queue<std::pair<int, int>>& startingRustTiles,
                       std::queue<std::pair<int, int>>& newRustTiles) {
    constexpr int directionsCount = 4;
    constexpr char normalTile = '.';
    constexpr char rustTile = '!';

    std::array<std::pair<int, int>, directionsCount> dirs {
        std::pair<int, int> { 0, 1 }, // right
        std::pair<int, int> { 1, 0 }, // down
        std::pair<int, int> { 0, -1 }, // left
        std::pair<int, int> { -1, 0 } // up
    };

    while (!startingRustTiles.empty()) {
        auto currRustTile = startingRustTiles.front();
        startingRustTiles.pop();

        for (const auto& dir : dirs) {
            auto modifiedDirRustTile = currRustTile;
            modifiedDirRustTile.first += dir.first;
            modifiedDirRustTile.second += dir.second;

            const bool isInBoundary = isInBounds(modifiedDirRustTile.first,
                modifiedDirRustTile.second);

            if (!isInBoundary) {
                continue;
            }

            char& currTile = matrix[modifiedDirRustTile.first][modifiedDirRustTile.second];
            if (normalTile != currTile) {
                continue;
            }

            currTile = rustTile;
            newRustTiles.push(modifiedDirRustTile);
        }
    }
}

void processSolution(std::array<std::array<char, size>, size>& matrix, 
                     int turns) {
    auto startingRustTiles = getInitialRustTiles(matrix);
    std::queue<std::pair<int, int>> newRustTiles;

    for (int i = 0; i < turns; ++i) {
        processSingleTurn(matrix, startingRustTiles, newRustTiles);
        std::swap(startingRustTiles, newRustTiles);
    }
}

void printMatrix(const std::array<std::array<char, size>, size>& matrix) {
    for (const auto& row : matrix) {
        for (const auto element : row) {
            std::cout << element;
        }
        std::cout << std::endl;
    }
}

int main() {
    auto matrix = ReadMatrixFromInput();
    const int turns = readTurnsFromInput();

    processSolution(matrix, turns);
    printMatrix(matrix);

    return 0;
}
