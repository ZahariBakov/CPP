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

    int sum = 0;
    std::ostringstream outputString;
    std::string current;
    
    std::istringstream lineStream(input);

    while (lineStream >> current) {
        char currentElement = current[0];

        if ((currentElement >= 'a' && currentElement <= 'z') || (currentElement >= 'A' && currentElement <= 'Z')) {
            outputString << current << " ";
        }
        else {
            int num = stoi(current);
            sum += num;
        }
    }

    std::cout << sum << std::endl;
    std::cout << outputString.str() << std::endl;
}
