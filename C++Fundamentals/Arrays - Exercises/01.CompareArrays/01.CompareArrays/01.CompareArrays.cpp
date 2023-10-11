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

bool areEqual(vector<int> v1, int length1, vector<int> v2, int lenght2) {
    if (length1 != lenght2) {
        return false;
    }

    for (int i = 0; i < length1; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> arr1 = readSizedArray();
    vector<int> arr2 = readSizedArray();

    if (areEqual(arr1, arr1.size(), arr2, arr2.size())) {
        cout << "equal" << endl;
    }
    else {
        cout << "Not equal" << endl;
    }
}
