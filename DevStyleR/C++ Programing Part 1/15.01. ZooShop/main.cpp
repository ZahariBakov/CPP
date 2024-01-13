#include <vector>

#include "Dog.h"


int main() {
    Dog dog("Jack Russell", "Milo", 3, "Af-af");
    //dog.print();

    // Some tests:
    // Breed test:
    //Dog d1("B", "Sharo", 1.2, "bau bau"); // Beagle
    //d1.print();

    // Name test:
    //Dog d2("Bulldog", "C", 5.5, "Jaf Jaf"); // Charlie
    //d2.print();

    // Age test:
    //Dog d3("Poodle", "Bella", -1.5, "bark"); // 1.5
    //d3.print();

    Animal* animalPtr = &dog;

    // Here we declare a pointer to a 'Dog' object named 'dogPtr' and initialize it to 'nullptr'.
    // This pointer can hold the memory address of a 'Dog' object.
    Dog* dogPtr = nullptr;

    // This line is dynamically allocating memory for a new Dog object on the heap using the new operator.
    dogPtr = new Dog("Pudel", "Sharo", 2, "Jaf Jaf");

    //cout << dogPtr->getName() << endl;

    vector<Animal*> animals;
    animals.push_back(dogPtr);
    animals.push_back(animalPtr);

    for (size_t i = 0; i < animals.size(); ++i) {
        animals[i]->print();
        cout << endl;
    }

    vector<Animal> secondAnimals;
    secondAnimals.push_back(dog);

    for (size_t i = 0; i < secondAnimals.size(); ++i) {
        secondAnimals[i].print();
        cout << endl;
    }

    dog.print();
    
    // It is important to note that when 'new' is used, 
    // the allocated memory must be freed later using 'delete' to avoid a memory leak.
    delete dogPtr;
    dogPtr = nullptr;

    return 0;
}
