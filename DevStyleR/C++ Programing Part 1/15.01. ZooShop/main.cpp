#include <iostream>

#include "Dog.h"
#include <vector>

int main() {
    Dog dog("dog", "Maylo", 3, "Afaf");

    Animal* animalPtr = &dog;

    Dog* dogPtr = nullptr;
    dogPtr = new Dog("Pudel", "Sharo", 2, "JafJaf");

    cout << dogPtr->getName() << endl;

    vector<Animal*> animals;
    animals.push_back(dogPtr);
    animals.push_back(animalPtr);

    vector<Animal> secondAnimals;
    secondAnimals.push_back(dog);

    delete dogPtr;
    dogPtr = nullptr;

    return 0;
}
