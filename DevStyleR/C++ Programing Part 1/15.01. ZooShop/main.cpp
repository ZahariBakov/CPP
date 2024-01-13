#include <vector>

#include "Dog.h"


int main() {
    Dog dog("Jack Russell", "Milo", 3, "Afaf");
    dog.print();

    // Some tests:
    // Breed test:
    Dog d1("B", "Sharo", 1.2, "bau bau"); // Beagle
    d1.print();

    // Name test:
    Dog d2("Bulldog", "C", 5.5, "Jaf Jaf"); // Charlie
    d2.print();

    // Age test:
    Dog d3("Poodle", "Bella", -1.5, "bark"); // 1.5
    d3.print();

    /*Animal* animalPtr = &dog;

    Dog* dogPtr = nullptr;
    dogPtr = new Dog("Pudel", "Sharo", 2, "JafJaf");

    cout << dogPtr->getName() << endl;

    vector<Animal*> animals;
    animals.push_back(dogPtr);
    animals.push_back(animalPtr);

    vector<Animal> secondAnimals;
    secondAnimals.push_back(dog);

    delete dogPtr;
    dogPtr = nullptr;*/

    return 0;
}
