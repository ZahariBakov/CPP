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

int divisionNumbers(int x, int y) {
    return x / y;
}

int main()
{
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;

    int result;
    bool validOperator = false;
    bool divideByZero = false;

    while (!validOperator) {
        char oper;
        cin >> oper;
        validOperator = true;

        switch (oper) {
            case '+':
                result = sumNumbers(firstNum, secondNum);
                break;
            case '-':
                result = subtractionNumbers(firstNum, secondNum);
                break;
            case '*':
                result = multiplicationNumbers(firstNum, secondNum);
                break;
            case '/':
                if ((firstNum == 0) || (secondNum == 0)) {
                    divideByZero = true;
                    break;
                }
                else {
                    result = divisionNumbers(firstNum, secondNum);
                    break;
                }
            default:
                validOperator = false;
                cout << "try again" << endl;
                break;
        }
    }

    if (divideByZero) {
        cout << "Can't divide by zero.";
    }
    else {
        cout << result << endl;
    }
}
