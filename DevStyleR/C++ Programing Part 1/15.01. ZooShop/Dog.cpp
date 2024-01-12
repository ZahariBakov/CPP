#include "Dog.h"

Dog::Dog(string kind, string name, int year, string bark) : Animal(kind, name, year) {
	setBark(bark);
}

void Dog::setBark(string bark) {
	this->bark = bark;
}

string Dog::getBark() {
	return this->bark;
}

void Dog::print() {
	Animal::print();

	cout << this->bark;
}
