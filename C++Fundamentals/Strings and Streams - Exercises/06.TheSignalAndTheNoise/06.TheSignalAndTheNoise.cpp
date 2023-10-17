#include <iostream>
#include <string>
#include <sstream>

std::string readInput() {
    std::string line;
    getline(std::cin, line);

    return line;
}

int main()
{
    std::string input = readInput();

    std::istringstream lineStream(input);
    std::string current;
    int maxNum = INT8_MIN;

    while (lineStream >> current) {
        int currentNum = 0;

        for (int i = 0; i < current.size(); i++) {
            char c = current[i];

            if (c >= '0' && c <= '9') {
                currentNum = currentNum * 10 + (c - '0');
            }
        }

        if (currentNum > maxNum) {
            maxNum = currentNum;
        }
    }   

    std::cout << maxNum << std::endl;

    return 0;
}
