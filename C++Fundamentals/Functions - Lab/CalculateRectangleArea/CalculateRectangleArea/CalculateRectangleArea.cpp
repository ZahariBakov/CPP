#include <iostream>
using namespace std;

void printRectangleArea(int a, int b) {
    int result = a * b;

    cout << result << endl;
}

int main()
{
    int width;
    int height;

    cin >> width;
    cin >> height;

    printRectangleArea(width, height);
}
