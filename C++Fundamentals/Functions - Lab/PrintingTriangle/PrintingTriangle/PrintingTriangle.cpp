#include <iostream>
using namespace std;

void printUpperPart(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
}

void printLowerPart(int x) {
    for (int i = x; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num;
    cin >> num;

    printUpperPart(num);
    printLowerPart(num);
}
