#include <iostream>
#include <string>
#include <stack>

std::string readNewUrl() {
    std::string url;
    std::cin >> url;

    return url;
}

void addNewUrl(const std::string& newUrl, std::stack<std::string>& history) {
    history.push(newUrl);
    std::cout << "Current URL: " << newUrl << std::endl;
}

void executeBackInstruction(std::stack<std::string>& history) {
    if (history.empty()) {
        std::cout << "no previous URLs" << std::endl;
    }
    else {
        history.pop();

        if (history.empty()) {
            std::cout << "At homepage" << std::endl;
        }
        else {
            const std::string& lastUrl = history.top();
            std::cout << "Current URL: " << lastUrl << std::endl;
        }
    }
}

int main() {
    std::stack<std::string> history;
    const std::string delimiter = "end";
    const std::string backInstruction = "/back";
    std::string currUrl;

    while (true) {
        currUrl = readNewUrl();

        if (currUrl == delimiter) {
            break;
        }

        if (currUrl == backInstruction) {
            executeBackInstruction(history);
        }
        else {
            addNewUrl(currUrl, history);
        }
    }

    return 0;
}
