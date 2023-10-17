#include <iostream>
#include <string>
#include <cctype>

std::string readInput() {
    std::string line;
    getline(std::cin, line);

    return line;
}

void capitalizaFirstWordLetter(std::string& msg) {
    bool hasWordStarter = false;

    const size_t msgSize = msg.size();

    for (size_t i = 0; i < msgSize; ++i) {
        if (isalpha(msg[i])) {
            if (!hasWordStarter) {
                hasWordStarter = true;
                msg[i] = toupper(msg[i]);
            }
        }
        else {
            hasWordStarter = false;
        }
    }
}

int main()
{
    std::string input = readInput();
    capitalizaFirstWordLetter(input);

    std::cout << input << std::endl;
}
