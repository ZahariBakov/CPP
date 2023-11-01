#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <sstream>
#include <iterator>
#include <queue>

std::queue<double> readInput() {
    std::queue<double> values;

    std::string input;
    getline(std::cin, input);

    std::istringstream istr(input);
    double value;

    while (istr >> value) {
        values.push(value);
    }

    return values;
}

void countSameDouble(std::queue<double>& values,
                     std::map<double, int>& valuesMap,
                     std::vector<double>& valuesVector) {
    double currValue;

    while (!values.empty()) {
        currValue = values.front();
        values.pop();

        if (valuesMap.find(currValue) != valuesMap.end()) {
            valuesMap[currValue]++;
        }
        else {
            valuesMap[currValue] = 1;
            valuesVector.push_back(currValue);
        }
    }
}

void printOutput(std::map<double, int>& valuesMap,
                 std::vector<double>& valuesVector) {
    for (int i = 0; i < valuesVector.size(); ++i) {
        double key = valuesVector[i];
        std::cout << key << " - " << valuesMap[key] << " times" << std::endl;
    }
}

int main() {
    std::queue<double> values = readInput();
    std::map<double, int> valuesMap;
    std::vector<double> valuesVector;

    countSameDouble(values, valuesMap, valuesVector);

    printOutput(valuesMap, valuesVector);

    return 0;
}
