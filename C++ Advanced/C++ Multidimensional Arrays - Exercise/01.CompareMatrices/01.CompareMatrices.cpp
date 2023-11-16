#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> readVec1DFromInput() {
    std::vector<int> vec1D;
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    int currNum = 0;

    while (istr >> currNum) {
        vec1D.push_back(currNum);
    }

    return vec1D;
}

std::vector<std::vector<int>> readVec2DFromInput() {
    int rows = 0;
    std::cin >> rows;
    std::cin.ignore();

    std::vector<std::vector<int>> vec2D(rows);

    for (auto& row : vec2D) {
        row = readVec1DFromInput();
    }

    return vec2D;
}

std::vector<std::vector<std::vector<int>>> readVec3DFromInput(int size) {
    std::vector<std::vector<std::vector<int>>> vec3D(size);

    for (auto& vec2D : vec3D) {
        vec2D = readVec2DFromInput();
    }

    return vec3D;
}

bool areEqualVector(const std::vector<int>& firstVec1D,
                    const std::vector<int>& secondVec1D) {
    const size_t size = firstVec1D.size();

    if (size != secondVec1D.size()) {
        return false;
    }

    for (size_t i = 0; i < firstVec1D.size(); ++i) {
        if (firstVec1D[i] != secondVec1D[i]) {
            return false;
        }
    }

    return true;
}

bool areEqualMatrix(const std::vector<std::vector<int>>& firstVec2D, 
                    const std::vector<std::vector<int>>& secondVec2D) {
    const size_t size = firstVec2D.size();

    if (size != secondVec2D.size()) {
        return false;
    }

    for (size_t i = 0; i < size; ++i) {
        const bool areEqual = areEqualVector(firstVec2D[i], secondVec2D[i]);

        if (!areEqual) {
            return false;
        }
     }

    return true;
}

void pritSolution(bool areEqual) {
    if (areEqual) {
        std::cout << "equal" << std::endl;
    }
    else {
        std::cout << "not equal" << std::endl;
    }
}

int main() {
    const auto numberOfVectors = 2;
    const auto vec3D = readVec3DFromInput(numberOfVectors);
    const bool areEual = areEqualMatrix(vec3D[0], vec3D[1]);
    pritSolution(areEual);

    return 0;
}
