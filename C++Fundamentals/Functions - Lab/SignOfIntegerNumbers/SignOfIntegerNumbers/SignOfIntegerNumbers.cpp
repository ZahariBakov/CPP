#include <iostream>
using namespace std;

void printSign(int x) {
    string sign;

    if (x > 0) {
        sign = "positive";
    }
    else {
        if (x < 0) {
            sign = "negative";
        }
        else {
           sign = "zero";
        }
    }

    cout << "The number " << x << " is " <<  sign << ".";
}

int main()
{
    int num;
    cin >> num;

    printSign(num);

    return 0;
}
