#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age = 0;
    double heightMeters = 0;

    // Name shadowing
    // Person(std::string name, int age, double heightMeters) {
    //     name = name;
    //     age = age;
    //     heightMeters = heightMeters;
    // }

    // Correct way (for using constructor body) - explicitly accessing the fields
    // through the "this" pointer
    Person(std::string name, int age, double heightMeters) {
        this->name = name;
        this->age = age;
        this->heightMeters = heightMeters;
    }
};

void printPersonInfo(const Person person) {
    std::cout << "name: " << person.name << ", age: " << person.age << ", height: " 
        << person.heightMeters << std::endl;
}

int main() {
    printPersonInfo(Person("Ary O'usure", 42, 1.3));

    return 0;
}
