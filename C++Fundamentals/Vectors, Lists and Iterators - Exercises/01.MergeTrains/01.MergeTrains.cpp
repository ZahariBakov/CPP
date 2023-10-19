#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers{ 1, 3, 5 };
    const int searchNumber = 4;

    std::vector<int>::const_iterator it = std::lower_bound(numbers.begin(), numbers.end(), searchNumber);

    if (it == numbers.end()) {
        std::cout << "not found" << std::endl;
    }
    else {
        // std::cout << *it << std::endl;

        if (*it == searchNumber) {
            std::cout << "Found the number: " << searchNumber << std::endl;
        }
        else {
            std::cout << "Did not find the number " << searchNumber << ", but it should be inserted into pos : " << it - numbers.begin() << std::endl;
        }
    }
}
