#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Person {
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name(name), age(age) {}

    std::string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }
};

std::vector<Person*>* getPeople() {
    std::vector<Person*>* people = new std::vector<Person*>();

    people->push_back(new Person("Ben Dover", 42));
    people->push_back(new Person("BAry O'usure", 25));

    return people;
}

std::shared_ptr<Person> getOlder(std::shared_ptr<Person> a, std::shared_ptr<Person> b) {
    if (a->getAge() > b->getAge()) {
        return a;
    }

    return b;
}

void printPerson(std::shared_ptr<Person> p) {
    std::cout << p->getName() << " " << p->getAge() << std::endl;
}

int main() {
    std::shared_ptr<Person> longestCopy;

    {
        std::shared_ptr<Person> person = std::make_shared<Person>("John Mc'Gill", 23);
        std::shared_ptr<Person> copy = person;
        longestCopy = copy;
        // person and copy go out of scope here, but memory is NOT
        // deallocated because longestCopy still points to it
    }

    std::cout << longestCopy->getName() << std::endl;

    std::vector<std::shared_ptr<Person> > people{
        std::shared_ptr<Person>(new Person("Youn Ger", 25)),
        std::make_shared<Person>("Ben Dover", 42)
    };

    printPerson(getOlder(people[0], people[1]));

    return 0;
}
