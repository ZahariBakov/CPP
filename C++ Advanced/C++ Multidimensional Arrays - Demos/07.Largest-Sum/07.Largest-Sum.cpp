#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <thread>

void printMaxColSum(const std::vector<std::vector<int>>& vec2D) {
    // std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    const auto start = std::chrono::high_resolution_clock::now();

    int maxSum = INT32_MIN;
    int colIndex = 0;
    const size_t arrSize = vec2D.size();

    for (size_t i = 0; i < arrSize; ++i) {
        int localSum = 0;

        const size_t innerSize = vec2D[i].size();

        for (size_t j = 0; j < innerSize; ++j) {
            localSum += vec2D[j][i];
        }

        if (maxSum < localSum) {
            maxSum = localSum;
            colIndex = i;
        }
    }

    std::cout << colIndex << std::endl;

    const auto end = std::chrono::high_resolution_clock::now();
    const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Operation took: " << elapsed.count() << " ms" << std::endl;

    /*for (size_t i = 0; i < arrSize; ++i) {
        std::cout << "arr[" << i << "]: " << vec2D[i][colIndex] << std::endl;
    }*/

}

std::vector<std::vector<int>> createRandomVec2D(int size) {
    std::vector<std::vector<int>> vec2D(size, std::vector<int>(size));

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> range(0, 100);

    for (auto& row : vec2D) {
        for (auto& elem : row) {
            elem = range(generator);
        }
    }

    return vec2D;
}

int main() {
    const auto size = 10000;
    const auto vec2D = createRandomVec2D(size);

    printMaxColSum(vec2D);

    return 0;
}
