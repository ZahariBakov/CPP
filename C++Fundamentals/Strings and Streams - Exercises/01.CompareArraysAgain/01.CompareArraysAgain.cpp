#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool compareArrays(const std::vector<int>& arr1,
                   const std::vector<int>& arr2) {
    return arr1 == arr2;
}

std::vector<int> readArrFromInput() {
    std::vector<int> arr{};
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    int currentNumber = 0;

    while (istr >> currentNumber) {
        arr.push_back(currentNumber);
    }

    return arr;
}

int main()
{
    const std::vector<int> arr1 = readArrFromInput();
    const std::vector<int> arr2 = readArrFromInput();
     
    const bool result = compareArrays(arr1, arr2);

    if (result) {
        std::cout << "equal" << std::endl;
    }
    else {
        std::cout << "not equal" << std::endl;
    }

    return 0;
}
