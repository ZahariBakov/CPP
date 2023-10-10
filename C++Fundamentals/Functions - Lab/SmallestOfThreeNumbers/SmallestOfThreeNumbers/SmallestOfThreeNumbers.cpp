#include <iostream>
using namespace std;

int minNum(int a, int b) {
    if (a < b) {
        return a;
    }

    return b;
}

int main()
{
    int firstNum;
    int secodnNum;
    int thirdNum;

    cin >> firstNum;
    cin >> secodnNum;
    cin >> thirdNum;

    cout << minNum(firstNum, minNum(secodnNum, thirdNum));
}
