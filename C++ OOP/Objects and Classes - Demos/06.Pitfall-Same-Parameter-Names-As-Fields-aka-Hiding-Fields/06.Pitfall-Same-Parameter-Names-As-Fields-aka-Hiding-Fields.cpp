#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age = 0;
    double heightMeters = 0;

     Person(std::string inputName, int inputAge, double inputHeightMeters) {
         name = inputName;
         age = inputAge;
         heightMeters = inputHeightMeters;
     }

    // Correct way (for using constructor body) - explicitly accessing the fields
    // through the "this" pointer
    // Person(std::string name, int age, double heightMeters) {
    //     this->name = name;
    //     this->age = age;
    //     this->heightMeters = heightMeters;
    // }
};

void printPersonInfo(const Person person) {
    std::cout << "name: " << person.name << ", age: " << person.age << ", height: " 
        << person.heightMeters << std::endl;
}

int main() {
    printPersonInfo(Person("Ary O'usure", 42, 1.3));

    return 0;
}
