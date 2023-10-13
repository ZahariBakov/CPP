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
    vector<int> numbers = readSizedArray();

    int counts[10] = {};

    for (int i = 0; i < numbers.size(); i++) {
        counts[numbers[i]]++;
    }

    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
        }
    }

    for (int i = 0; i < 10; i++) {
        if (maxCount == counts[i]) {
            cout << i << " ";
        }
    }
}
