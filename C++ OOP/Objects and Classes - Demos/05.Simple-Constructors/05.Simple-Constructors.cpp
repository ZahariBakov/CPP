#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age = 0;
    double heightMeters = 0;

    Person(const std::string personName, int personAge, double personHeightMeters) {
        name = personName;
        age = personAge;
        heightMeters = personHeightMeters;
    }

    // Default constructor - allow is to not explicitly initialize when calling
    Person() {
        name = "<unknown>";
    }
};

void printPersonInfo(const Person person) {
    std::cout << "name: " << person.name << ", age: " << person.age << ", height: " << person.heightMeters << std::endl;
}

int main() {
    const Person ben("Ben Dover", 42, 1.69);
    const Person chucky = Person("Chuck Norris", 999, 999.999);
    // NOTE: if we delete the default constructor (Person()) this line won't compile:
    const Person defaultPerson;

    printPersonInfo(ben);
    printPersonInfo(chucky);
    printPersonInfo(defaultPerson);
    printPersonInfo(Person("Tem Porary", 1, 1.0));


    return 0;
}
