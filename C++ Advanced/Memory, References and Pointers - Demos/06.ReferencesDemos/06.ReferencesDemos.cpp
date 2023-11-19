#include <iostream>
#include <vector>
#include <map>

int main() {
    std::map<int, std::vector<std::string>> localMap;

    auto& element = localMap[1];

    element.push_back("first");
    element.push_back("second");
    element.push_back("third");

    for (const auto& pair : localMap) {
        std::cout << "Key: " << pair.first << ", Value: ";

        const auto& values = pair.second;
        for (const auto& value : values) {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
