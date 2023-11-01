#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> range(0, 10);
    std::uniform_real_distribution<float> rangeFloat(0, 1);

    for (int i = 0; i < 10; ++i) {
        std::cout << range(generator) << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << rangeFloat(generator) << std::endl;
    }

    return 0;
}
