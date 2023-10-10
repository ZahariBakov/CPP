#include <iostream>
#include <cmath>
using namespace std;

void mathPower(int x, int y) {
    int result;

    if (y < 2) {
        result = x;
    }
    else {
        result = (x * x);
    }

    for (int i = 2; i < y; i++) {
        result *= x;
    }

    cout << result;
}

int main()
{
    int number;
    int power;

    cin >> number;
    cin >> power;

    //mathPower(number, power);
    cout << pow(number, power);
}
