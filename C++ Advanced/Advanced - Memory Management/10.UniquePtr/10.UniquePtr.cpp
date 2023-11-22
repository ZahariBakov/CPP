#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Person {
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name(name), age(age) {}

    std::string getName() {
        return this->name;
    }
};

std::unique_ptr<Person> getPerson() {
    Person* person = new Person("Ben Dover", 42);

    std::unique_ptr<Person> p;
    p.reset(person);

    return p;
}

int main() {
    std::unique_ptr<Person> personPtr(new Person("Jonh", 20));
    // std::unique_ptr<Person> personPtr = 
        // std::make_unique<Person>("Jonh", 20); // Equivalent to the above

    std::cout << personPtr->getName() << std::endl;
    // no need for delete, unique_ptr clears memory when it goes out of scope

    std::cout << getPerson()->getName() << std::endl;
    // again, no need for delete

    // compilation error, cannot copy unique ptr
    // std::unique_ptr<Pesron> invalidCopy = personPtr;

    return 0;
}
