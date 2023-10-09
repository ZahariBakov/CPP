#include <iostream>
using namespace std;

int main()
{
    int firstNum;
    int secondNum;
    int thirdNum;

    cin >> firstNum >> secondNum >> thirdNum;

    int sum = firstNum * secondNum * thirdNum;

    char result;

    if (sum < 0) {
        result = '-';
    }
    else {
        result = '+';
    }

    cout << result;
}
