#include <iostream>
#include <string>

std::string readInput() {
    std::string line;
    getline(std::cin, line);

    return line;
}

std::string findAndReplace(std::string& msg, std::string oldString, std::string newString) {
    std::size_t foundIndex = msg.find(oldString);

    while (foundIndex != std::string::npos) {
        msg.replace(foundIndex, oldString.size(), newString);
        foundIndex = msg.find(oldString, foundIndex + 1);
    }

    return msg;
}

int main()
{
    std::string input = readInput();
    std::string oldString = readInput();
    std::string newString = readInput();

    findAndReplace(input, oldString, newString);

    std::cout << input << std::endl;
}
