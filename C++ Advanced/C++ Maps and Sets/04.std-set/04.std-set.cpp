#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    using namespace std;

    // This is default ordering. Result will be: (0, 1, 2, 3, ....) 
    set<int> digits{ 4, 1, 4, 0, 2, 6, 9, 1, 8, 6, 2, 3, 5, 6, 7 };

    // This is greater ordering. Result will be: (9, 8, 7, 6,....)
    set<int, greater<int>> greaterDigits{ 4, 1, 4, 0, 2, 6, 9, 1, 8, 6, 2, 3, 5, 6, 7 };

    for (int d : digits)
    {
        cout << d << " ";
    }
    cout << endl;
    cout << endl;

    for (int d : greaterDigits)
    {
        cout << d << " ";
    }

    cout << endl;
    cout << endl;

    set<char> letters;
    string sentance = "the quick brown fox jumps over the lazy dog";
    istringstream sentenceIn(sentance);
    char letter;
    while (sentenceIn >> letter)
    {
        letters.insert(letter);
    }

    // for (set<char>::iterator i = letters.begin(); i != letters.end(); i++)
    // same upper and lower!
    for (auto i = letters.begin(); i != letters.end(); i++)
    {
        cout << *i;
    }
    cout << endl;

    return 0;
}
