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

vector<int> sumNumArr(vector<int> arr) {
    vector<int> numbers;
    int size = arr.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int currentNum = arr[i] * arr[j];
            numbers.push_back(currentNum);
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
    vector<int> sumNumbers = sumNumArr(numbers);
    printResult(sumNumbers);

}
