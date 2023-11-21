#include <iostream>
#include <vector>
#include <string>
#include <cstddef> // size_t

void waitForEnter(std::string message) {
    std::cout << message << std::endl;

    std::string s;
    std::getline(std::cin, s);
}

void allocateLargeAutoMemory() {
    int autoArr[1000];

    for (size_t i = 0; i < 1000; ++i) {
        autoArr[i] = i;
    }
}

void allocateLargeAutoVector() {
    std::vector<int> autoVector; // this will require 4GB if sizeof(int) == 4
    autoVector.reserve(10000000000);

    for (size_t i = 0; i < 10000000000; ++i) {
        autoVector.push_back(i);
    }

    waitForEnter("in allocateLargeAutoVector(), after filling vector - "
            "check memory, should be sizeof(int) MB more");
}

int main() {
    int autoVar = 42;

    for (int i = 0; i < 1000000; ++i) {
        int autoVarLoop = i * i;
        autoVar += autoVarLoop;
    }

    allocateLargeAutoMemory();

    waitForEnter("before alocateLargeAutoVector() - check memory usage");
    allocateLargeAutoVector();
    waitForEnter("after allocateLargeAutoVector() - "
        "memory usage now should match usage before");


    return 0;
}
