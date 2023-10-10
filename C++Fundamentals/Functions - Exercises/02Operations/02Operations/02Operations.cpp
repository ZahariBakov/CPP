#include <iostream>
using namespace std;

int sumNumbers(int x, int y) {
    return x + y;
}

int subtractionNumbers(int x, int y) {
    return x - y;
}

int multiplicationNumbers(int x, int y) {
    return x * y;
}

float divisionNumbers(float x, float y) {
    return x / y;
}

int main()
{
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;
    char oper;
    cin >> oper;

    switch (oper) {
        case '+':
            cout << sumNumbers(firstNum, secondNum);
            break;
        case '-':
            cout << subtractionNumbers(firstNum, secondNum);
            break;
        case '*':
            cout << multiplicationNumbers(firstNum, secondNum);
            break;
        default:
            if ((firstNum == 0) || (secondNum == 0)) {
                cout << "Can't divide by zero.";
                break;
            }
            else {
                cout << divisionNumbers(firstNum, secondNum);
                break;
            }
    }
}
