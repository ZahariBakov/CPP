#include <iostream>
#include <string>

class Person {
    class Body {
    public:
        double heightMeters;
        double weightKgs;

        Body(double heightMeters, double weightKgs) : heightMeters(heightMeters), weightKgs(weightKgs) {

        }
    };

public:
    std::string name;
    int age = 0;
    Body body;

    Person(std::string name, int age, double heightMeters, double weightKgs) :
        name(name), age(age), body(heightMeters, weightKgs) {

    }
};

void printPersonInfo(const Person person) {
    std::cout << "name: " << person.name << ", age: " << person.age << ", height: "
        << person.body.heightMeters << ", weight: " << person.body.weightKgs << std::endl;
}

int main() {
    printPersonInfo(Person("Prope Rinit", 42, 1.82, 82.3));

    return 0;
}
