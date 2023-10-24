#include <iostream>
#include <string>
#include <stack>

std::string readInput() {
    std::string input;
    getline(std::cin, input);

    return input;
}

void printSolution(bool result) {
    if (result == true) {
        std::cout << "valid" << std::endl;
    }
    else {
        std::cout << "invalid" << std::endl;
    }
}

bool calculatingbrackets(const std::string& input) {
    std::stack<char> brackets;
    bool isValid = true;
    bool result;
    

    for (char elem : input) {
        switch (elem) {
            case '(':
                brackets.push(')');
                break;
            case '{':
                brackets.push('}');
                break;
            case '[':
                brackets.push(']');
                break;
            case ')':
            case '}':
            case ']':
                if (brackets.empty() || brackets.top() != elem) {
                    isValid = false;
                }
                else {
                    brackets.pop();
                } 
                break;
            default:
                break;
        }

        if (!isValid) {
            break;
        }
    }  

    if (isValid && brackets.empty()) {
        result = true;
    }
    else {
        result =  false;
    }

    return result;
}

int main() {
    const std::string input = readInput();
    bool result = calculatingbrackets(input);
    printSolution(result);

    return 0;
}