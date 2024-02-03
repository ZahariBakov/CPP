#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Company.h"

int main() {
    std::vector<Company> companies;
    std::string line;

    while (std::getline(std::cin, line) && line != "end") {
        std::istringstream stream(line);

        std::string name;
        int id;
        stream >> name >> id;
        companies.push_back(Company{ id, name });
    }

    std::string sortBy;
    std::cin >> sortBy;

    bool(*lessThen)(const Company&, const Company&) = nullptr;

    if (sortBy == "name") {
        lessThen = [](const Company& a, const Company& b) {
            return a.getName() < b.getName();
            };
    }
    else if (sortBy == "id") {
        lessThen = [](const Company& a, const Company& b) {
            return a.getId() < b.getId();
            };
    }

    sort(companies.begin(), companies.end(), lessThen);

    for (Company c : companies) {
        std::cout << c.toString() << std::endl;
    }

    return 0;
}
