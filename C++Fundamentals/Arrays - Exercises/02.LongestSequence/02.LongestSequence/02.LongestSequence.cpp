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

int main()
{
    vector<int> arr = readSizedArray();

    int maxLength = 0;
    int longestNumber = 0;

    int curLength = 1;
    int curNumber = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (curNumber == arr[i]) {
            curLength++;
        }
        else {
            if (curLength >= maxLength) {
                maxLength = curLength;
                longestNumber = curNumber;
            }

            curLength = 1;
            curNumber = arr[i];
        }
    }

    if (curLength >= maxLength) {
        maxLength = curLength;
        longestNumber = curNumber;
    }

    for (int i = 0; i < maxLength; i++) {
        cout << longestNumber << " ";
    }
    cout << endl;
}
