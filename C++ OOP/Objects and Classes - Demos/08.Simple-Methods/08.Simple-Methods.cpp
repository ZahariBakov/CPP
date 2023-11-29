#include <iostream>
#include <string>

class Person {
    class Body {
    public:
        double heightMeters;
        double weightKgs;

        Body(double heightMeters, double weightKgs) 
            : heightMeters(heightMeters), weightKgs(weightKgs) {
        }
    };

public:
    // Class members
    std::string name;
    int age = 0;
    Body body;

    Person(std::string name, int age, double heightMeters, double weightKgs) 
        : name(name), age(age), body(heightMeters, weightKgs) {
    }

    // Class methods
    void makePersonOlder(int years) {
        this->age += years;
    }

    void printPersonInfo() {
        std::cout << "name: " << this->name << ", age: " << this->age << ", height: "
            << this->body.heightMeters << ", weight: " << this->body.weightKgs << std::endl;
    }
};

int main() {
    Person person("Met Hods", 42, 1.82, 82.3);

    Person anotherPerson("Met Hods2", 71, 1.82, 82.3);
    
    person.printPersonInfo();
    anotherPerson.printPersonInfo();

    Person* personPointer = &person;
    personPointer->makePersonOlder(1);
    personPointer->printPersonInfo();

    return 0;
}
