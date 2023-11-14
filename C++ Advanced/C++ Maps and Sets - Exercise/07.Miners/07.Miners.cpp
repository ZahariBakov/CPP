#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

void readInput(std::map<std::string, int>& resourses, std::vector<std::string>& order) {
    std::string resourse;
    int quantity = 0;

    while (true) {
        std::cin >> resourse;

        if (resourse == "stop") {
            break;
        }

        std::cin >> quantity;

        auto it = resourses.find(resourse);

        if (it == resourses.end()) {
            order.push_back(resourse);
            resourses[resourse] = 0;
        }

        resourses[resourse] += quantity;
    }
}

void printSolution(std::map<std::string, int>& resourses, std::vector<std::string>& order) {
    for (int i = 0; i < order.size(); ++i) {
        std::cout << order[i] << " -> " << resourses[order[i]] << std::endl;
    }
}

int main() {
    std::map<std::string, int> resourses;
    std::vector<std::string> order;
    readInput(resourses, order);
    printSolution(resourses, order);

    return 0;
}
