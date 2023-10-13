#include <iostream>
#include <vector>
using namespace std;

vector<int> readSizedArray() {
    vector<int> numbers;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int currentNum;
        cin >> currentNum;

        numbers.push_back(currentNum);
    }

    return numbers;
}

int calcAverage(vector<int> arr) {
    int totalSum = 0;
    int size = arr.size();

    for (int i = 0; i < size; i++) {
        totalSum += arr[i];
    }

    int average = totalSum / size;

    return average;
}

vector<int> bigNumbers(vector<int> arr, double average) {
    vector<int> numbers;

    for (int i = 0; i < arr.size(); i++) {
        int currentNumber = arr[i];

        if (currentNumber >= average) {
            numbers.push_back(currentNumber);
        }
    }

    return numbers;
}

void printResult(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> numbers = readSizedArray();
    int averageValue = calcAverage(numbers);
    vector<int> result = bigNumbers(numbers, averageValue);
    printResult(result);
}
