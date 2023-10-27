#include <iostream>
#include <string>
#include <stack>

std::string readNewUrl() {
    std::string url;
    std::cin >> url;

    return url;
}

void addNewUrl(const std::string& newUrl, 
               std::stack<std::string>& history, 
               std::stack<std::string>& forward) {
    history.push(newUrl);
    std::cout << "Current URL: " << newUrl << std::endl;

    forward = std::stack<std::string>();
}

void executeBackInstruction(std::stack<std::string>& history, 
                            std::stack<std::string>& forward) {
    if (history.empty()) {
        std::cout << "no previous URLs" << std::endl;
    }
    else {
        forward.push(history.top());
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

void executeForwardInstruction(std::stack<std::string>& history, 
                               std::stack<std::string>& forward) {
    if (forward.empty()) {
        std::cout << "no next URLs" << std::endl;
    }
    else {
        const std::string nextUrl = forward.top();
        std::cout << "Current URL: " << nextUrl << std::endl;
        history.push(nextUrl);
        forward.pop();
    }
}

int main() {
    std::stack<std::string> history;
    std::stack<std::string> forward;
    const std::string delimiter = "end";
    const std::string backInstruction = "/back";
    const std::string forwardInstruction = "/forward";
    std::string currUrl;

    while (true) {
        currUrl = readNewUrl();

        if (currUrl == delimiter) {
            break;
        }

        if (currUrl == backInstruction) {
            executeBackInstruction(history, forward);
        }
        else if (currUrl == forwardInstruction) {
            executeForwardInstruction(history, forward);
        }
        else {
            addNewUrl(currUrl, history, forward);
        }
    }

    return 0;
}
