#include <iostream>
using namespace std;

void printGade(double x) {
    string result;

    if (x < 3.00) {
        result = "Fail";
    }
    else {
        if (x < 3.50) {
            result = "Poor";
        }
        else {
            if (x < 4.50) {
                result = "Good";
            }
            else {
                if (x < 5.50) {
                    result = "Very good";
                }
                else {
                    result = "Excellent";
                }
            }
        }
    }

    cout << result;
}

int main()
{
    double grade;

    cin >> grade;

    printGade(grade);
}
