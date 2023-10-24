#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> readInput(int n) {
    std::vector<int> pipe(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> pipe[i];
    }

    return pipe;
}

std::vector<int> timeForReplace(int n, std::vector<int>& checkup, std::vector<int>& installation) {
    std::vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        int currentDamage = installation[i] - checkup[i];
        result[i] = installation[i] / currentDamage;
    }

    return result;
}

void printSolution(int n, std::vector<int>& result) {
    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " ";
    }
}

int main() {
    int numbers_of_pipe;
    std::cin >> numbers_of_pipe;

    std::vector<int> checkup = readInput(numbers_of_pipe);
    std::vector<int> installation = readInput(numbers_of_pipe);

    std::vector<int> result = timeForReplace(numbers_of_pipe, checkup, installation);

    printSolution(numbers_of_pipe, result);

    return 0;
}
