#include <iostream>
#include <string>
#include <sstream>

std::string readInput() {
    std::string line;
    getline(std::cin, line);

    return line;
}

int main() {
    std::string input = readInput();

    std::istringstream lineStream(input);
    std::string current;
    std::string longestString;

    while (lineStream >> current) {
        std::string noise = "";

        for (int i = 0; i < current.length(); i++) {
            char c = current[i];

            if (!(c >= '0' && c <= '9')) {
                noise += c;
            }
        }

        if (noise.length() > longestString.length()) {
            longestString = noise;
        }
        else if (noise.length() == longestString.length()) {
            if (noise < longestString) {
                longestString = noise;
            }
        }
    }

    if (longestString != "") {
        std::cout << longestString << std::endl;
    }
    else {
        std::cout << "no noise" << std::endl;
    }
}
