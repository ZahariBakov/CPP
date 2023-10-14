#include <iostream>
#include <vector>
#include <cstdlib>

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

int returnMinDiff(vector<int> arr) {
    int minDifference = INT8_MAX;

    for (int firstNumIndex = 0; firstNumIndex < (arr.size() - 1); firstNumIndex++) {
        int firstNum = arr[firstNumIndex];

        for (int secodnNumIndex = firstNumIndex + 1; secodnNumIndex < arr.size(); secodnNumIndex++) {
            int secondNum = arr[secodnNumIndex];

            int currentDifference = abs(firstNum - secondNum);

            if (minDifference >= currentDifference) {
                minDifference = currentDifference;
            }
        }
    }

    if (minDifference == INT8_MAX) {
        minDifference = 0;
    }

    return minDifference;
}

int main()
{
    vector<int> numbers = readSizedArray();
    cout << returnMinDiff(numbers);
}
