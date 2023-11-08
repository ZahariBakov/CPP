#include <iostream>
#include <map>

std::map<int, int> readInput() {
    std::map<int, int> numbers;
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        numbers[num]++;
    }

    return numbers;
}

void printSolution(std::map<int, int >& numbers) {
    for (std::pair<int, int>el : numbers) {
        if (el.second % 2 == 0) {
            std::cout << el.first << std::endl;
            break;
        }
    }
}

int main() {
    std::map<int, int> numbers = readInput();

    std::cout << std::endl;

    printSolution(numbers);

    return 0;
}
