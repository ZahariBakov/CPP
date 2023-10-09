#include <iostream>
using namespace std;

int main()
{
    int firstNumber;
    int secondNumber;

    cin >> firstNumber >> secondNumber;

    if (firstNumber < secondNumber) {
        cout << firstNumber << " " << secondNumber;
    }
    else
    {
        cout << secondNumber << " " << firstNumber;
    }
}
