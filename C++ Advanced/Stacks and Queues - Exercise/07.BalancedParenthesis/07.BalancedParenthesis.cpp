#include <iostream>
#include <sstream>
#include <string>
#include <stack>

bool isCorrect(const std::string& line) {
    std::stack<char> parenth;

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];

        switch (c)
        {
        case '(':
        case '{':
        case '[':
            parenth.push(c);
            break;

        default:
            if (parenth.empty())
                return false;
            char top = parenth.top(); parenth.pop();

            if (c == ')' && top != '(')
                return false;

            if (c == '}' && top != '{')
                return false;

            if (c == ']' && top != '[')
                return false;
            break;
        }
    }

    return true;
}

int main()
{
    std::string line;
    getline(std::cin, line);

    std::cout << (isCorrect(line) ? "YES" : "NO") << std::endl;

    return 0;
}