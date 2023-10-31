#include <iostream>
#include <map>

std::string findEntryName(const std::map<int, std::string>& numberNames, 
                          int key, const std::string& defaultValue) {
    auto it = numberNames.find(key);
    if (it != numberNames.end()) {
        return it->second;
    }

    return defaultValue;
}

int main() {
    using namespace std;

    map<int, string> numberNames{ {2, "two"} };

    /*for (unsigned long i = 0; i < numberNames.size(); i++)
    {
        cout << numberNames[i] << ",";
    }*/

    cout << findEntryName(numberNames, 2, "test");

    return 0;
}
