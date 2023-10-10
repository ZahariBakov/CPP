#include <iostream>
using namespace std;

int long findFactorial(int long x) {
    int long y = 1;

    for (int i = 1; i <= x; i++) {
        y *= i;
    }

    return y;
}

double long divideFactorials(double long x, double long y) {
    return x / y;
}

int main()
{
    int long firstNum;
    int long secodnNum;

    cin >> firstNum;
    cin >> secodnNum;

    int long firstFactorial = findFactorial(firstNum);
    int long secondFactorial = findFactorial(secodnNum);

    double long result = divideFactorials(firstFactorial, secondFactorial);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << result << endl;
}
