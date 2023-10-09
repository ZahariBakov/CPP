#include <iostream>
using namespace std;

int main()
{
    int num, minNum, maxNum;
    minNum = INT8_MAX;
    maxNum = INT8_MIN;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int currentNum;
        cin >> currentNum;

        if (currentNum > maxNum) {
            maxNum = currentNum;
        }

        if (currentNum < minNum) {
            minNum = currentNum;
        }
    }

    cout << minNum << " " << maxNum;
}
