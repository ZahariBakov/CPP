#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

int main()
{
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;

    cout << gcd(firstNum, secondNum);
}
