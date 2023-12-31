#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

class Company {
public:
    Company(int id, std::string name, std::vector<std::pair<char, char>> employees);

    int getId() const;

    std::string getName() const;

    std::vector<std::pair<char, char>> getEmployees() const;

    std::string toString() const;

    bool operator==(const Company& other) const;

    std::string operator+(const std::string& s);

    Company& operator+=(const std::pair<char, char>& employee);

private:
    int id;
    std::string name;
    std::vector<std::pair<char, char>> employees;
};

Company::Company(int id, std::string name, std::vector<std::pair<char, char>> employees)
    : id(id)
    , name(name)
    , employees(employees) {}

int Company::getId() const {
    return this->id;
}

std::string Company::getName() const {
    return this->name;
}

std::vector<std::pair<char, char>> Company::getEmployees() const {
    return this->employees;
}

std::string Company::toString() const {
    std::ostringstream stream;
    stream << id << " " << name << " ";

    for (size_t i = 0; i < employees.size(); ++i) {
        auto initials = employees[i];
        stream << initials.first << initials.second;

        if (i < employees.size() - 1) {
            stream << " ";
        }
    }
    
    return stream.str();
}

bool Company::operator==(const Company& other) const {
    return this->id == other.id;
}

std::string Company::operator+(const std::string& s) {
    return this->toString() + s;
}

Company& Company::operator+=(const std::pair<char, char>& employee) {
    this->employees.push_back(employee);

    return *this;
}

int main() {
    Company c(42, "TheAnswer Inc.", { { 'G', 'L' },{ 'H', 'F' },{ 'G', 'G' } });

    c += { 'W', 'P' };

    std::cout << c + " <- this is a cool company" << std::endl;

    return 0;
}
