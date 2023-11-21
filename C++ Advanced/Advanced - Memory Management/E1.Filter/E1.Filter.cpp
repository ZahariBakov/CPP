#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void print(const std::vector<int>& v) {
    for (const int item : v) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
}

// filter
// numbers > 3
// even Numbers
// negative Numbers

std::vector<int> filter(const std::vector<int>& numbers, 
                        const std::function<bool(int number)>& shouldFilter) {
    std::vector<int> filtered;

    for (const int currNumber : numbers) {
        if (shouldFilter(currNumber)) {
            filtered.push_back(currNumber);
        }
    }

    return filtered;
}

bool isBiggerThan3(int number) {
    return number > 3;
}

bool isNumberEven(int number) {
    return number % 2 == 0;
}

int main() {
    const std::vector<int> initialVec = { 1, 2, 3, 4, -503, 5, 6, 7 };
    std::vector<int> vec = filter(initialVec, isBiggerThan3);
    print(vec);

    vec = filter(initialVec, isNumberEven);
    print(vec);

    /*vec = filter(initialVec, [](int number) {
        return number < 0;
        });
    print(vec);*/

    std::function<bool(int number)> isNegativeNimber = [](int number) {
        return number < 0;
        };

    /*std::vector<int> arr{ 0, -4, 2 };
    std::vector<std::pair<int, int>> arrPairs(3);

    for (int i = 0; i < (int)arr.size(); ++i) {
        arrPairs[i].first = arr[i];
        arrPairs[i].second = i;
    }

    std::sort(arrPairs.begin(), arrPairs.end(),
        [](const std::pair<int, int>& left, const std::pair<int, int>& right) {
            return left.first < right.first;
        });

    for (const auto& pair : arrPairs) {
        std::cout << pair.first << ' ' << pair.second << std::endl;
    }*/

    vec = filter(initialVec, isNegativeNimber);

    print(vec);

    return 0;
}
