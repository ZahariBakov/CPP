#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int evenNumbers = 0;
    int oddNumbers = 0;
    int number;
    cin >> number;

    while (abs(number) > 0) {
        int currentNumber = number % 10;
        number /=  10;

        if (currentNumber % 2 == 0) {
            evenNumbers += currentNumber;
        }
        else {
            oddNumbers += currentNumber;
        }
    }

    int result = evenNumbers * oddNumbers;

    cout << result << endl;
}
