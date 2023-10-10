#include <iostream>
using namespace std;


string numToString(int x) {
    string result;

    switch (x) {
        case 0:
            result = "zero";
            break;
        case 1:
            result = "one";
            break;
        case 2:
            result = "two";
            break;
        case 3:
            result = "three";
            break;
        case 4:
            result = "four";
            break;
        case 5:
            result = "five";
            break;
        case 6:
            result = "six";
            break;
        case 7:
            result = "seven";
            break;
        case 8:
            result = "eight";
            break;
        case 9:
            result = "nine";
            break;
    }

    return result;
}

string secondNumToString(int x) {
    string result;

    switch (x) {
        case 10:
            result = "ten";
            break;
        case 11:
            result = "eleven";
            break;
        case 12:
            result = "twelve";
            break;
        case 13:
            result = "thirteen";
            break;
        case 14:
            result = "fourteen";
            break;
        case 15:
            result = "fifteen";
            break;
        case 16:
            result = "sixteen";
            break;
        case 17:
            result = "seventeen";
            break;
        case 18:
            result = "eighteen";
            break;
        case 19:
            result = "nineteen";
            break;
        case 20:
            result = "twenty";
            break;
        case 30:
            result = "thirty";
            break;
        case 40:
            result = "forty";
            break;
        case 50:
            result = "fifty";
            break;
        case 60:
            result = "sixty";
            break;
        case 70:
            result = "seventy";
            break;
        case 80:
            result = "eighty";
            break;
        case 90:
            result = "ninety";
            break;
    }

    return result;
}

int main()
{
    string result;
    int number;
    cin >> number;

    int firstNum = number / 1000;
    number %= 1000;

    int secondNum = number / 100;
    number %= 100;

    int thirdNum = number / 10;
    number %= 10;

    int fourthNum = number;

    if (firstNum > 0) {
        result = numToString(firstNum) + " thousand ";
    }

    if (secondNum > 0) {
        result += numToString(secondNum) + " hundred ";
    }

    if (thirdNum > 0) {
        if (thirdNum == 1) {
            result += secondNumToString(fourthNum + 10);
        }
        else {
            result += secondNumToString(thirdNum * 10) + " ";
        }
    }

    if (thirdNum == 0 || thirdNum > 1) {
        result += numToString(fourthNum);
    }

    cout << result << endl;
}
