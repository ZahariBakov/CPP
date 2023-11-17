// DFS solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

std::vector<std::vector<char>> readMatrixFromInput() {
    int width = 0;
    int height = 0;
    std::cin >> width >> height;

    std::vector<std::vector<char>> matrix(height, std::vector<char>(width));

    for (auto& row : matrix) {
        for (auto& elem : row) {
            std::cin >> elem;
        }
    }

    return matrix;
}

std::vector<std::pair<int, int>> readCommandsFromInput() {
    int commandsSize = 0;
    std::cin >> commandsSize;

    std::vector<std::pair<int, int>> commands(commandsSize);
    
    for (auto& pair : commands) {
        std::cin >> pair.first >> pair.second;
    }

    return commands;
}

bool isInBoundary(const std::vector<std::vector<char>>& matrix, 
                  int currX, int currY) {
    if (0 > currX || 0 > currY) {
        return false;
    }

    if (currY >= int(matrix.size())) {
        return false;
    }

    if (currX >= int(matrix[0].size())) {
        return false;
    }
    
    return true;
}

void DFS(int currX, int currY, 
         std::vector<std::vector<char>>& matrix,
         std::stack<std::pair<int, int>>& futureCoords,
         int& currLakeSize) {
    const bool isInside = isInBoundary(matrix, currX, currY);
    if (!isInside) {
        return;
    }
    char currTile = matrix[currY][currX];
    const char landMarker = '#';


    if (currTile == landMarker) {
        return;
    }

    ++currLakeSize;
    matrix[currY][currX] = landMarker;

    futureCoords.push(std::make_pair(currX + 1, currY)); // go right
    futureCoords.push(std::make_pair(currX, currY + 1)); // go down
    futureCoords.push(std::make_pair(currX - 1, currY)); // go left
    futureCoords.push(std::make_pair(currX, currY - 1)); // go up
}

std::vector<int> executeCommands(const std::vector<std::vector<char>>& matrix, 
                                 const std::vector<std::pair<int, int>>& commands) {
    std::vector<int> results;
    results.reserve(commands.size());
    int currLakeSize = 0;
    std::vector<std::vector<char>> matrixCopy;
    std::stack<std::pair<int, int>> futureCoords;
    std::pair<int, int> currCoord;

    for (const auto& pair : commands) {
        // reset
        currLakeSize = 0;
        matrixCopy = matrix;
        futureCoords.push(pair);

        while (!futureCoords.empty()) {
            currCoord = futureCoords.top();
            futureCoords.pop();

            // process
            DFS(currCoord.first, currCoord.second, matrixCopy, futureCoords, currLakeSize);
        }

        // push result
        results.push_back(currLakeSize);
    }

    return results;
}

void printSolution(const std::vector<int>& results) {
    for (const int result : results) {
        std::cout << result << "\n";
    }
    std::cout << std::endl;
}

int main() {
    const auto matrix = readMatrixFromInput();
    const auto commands = readCommandsFromInput();
    const auto results = executeCommands(matrix, commands);

    printSolution(results);

    return 0;
}

// https://www.codingame.com/ide/puzzle/surface
