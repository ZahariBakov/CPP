#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <thread>
#include <algorithm>

void printMaxColSum(const std::vector<std::vector<int>>& vec2D) {
    // std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    const auto start = std::chrono::high_resolution_clock::now();

    const size_t arrSize = vec2D.size();

    std::vector<int> sums(arrSize);

    for (size_t i = 0; i < arrSize; ++i) {

        const size_t innerSize = vec2D[i].size();

        for (size_t j = 0; j < innerSize; ++j) {
            sums[j] += vec2D[i][j];
        }
    }
    
    const size_t index = std::max_element(sums.begin(), sums.end()) - sums.begin();
    
    std::cout << index << std::endl;

    const auto end = std::chrono::high_resolution_clock::now();

    const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Operation took: " << elapsed.count() << " ms" << std::endl;
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
    const auto size = 15000;
    const auto vec2D = createRandomVec2D(size);

    printMaxColSum(vec2D);

    return 0;
}
