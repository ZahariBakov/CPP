#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    vector<int> numsVector{ 61, 41, 231, 764, 45 };
    sort(numsVector.begin(), numsVector.end(), std::greater<int>());
    for (int num : numsVector) 
    {
        cout << num << " ";
    }
    cout << endl << endl;

    string wordsArray[6]{ "whales", "cats", "dogs", "fish", "cheetah", "dodos" };

    const int arrSize = 6;
    auto beginIt = wordsArray;         // <- SAME -> // std::begin(wordsArray);
    auto endIt = wordsArray + arrSize; // <- SAME -> //std::end(wordsArray);
    sort(beginIt, endIt);              // sorting all six elements.
    
    // sort(wordsArray, wordsArray + 6); // sorting all six elements.
    // sort(wordsArray, wordsArray + 2); // sorting only the first two elements.
    for (string& word : wordsArray)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
