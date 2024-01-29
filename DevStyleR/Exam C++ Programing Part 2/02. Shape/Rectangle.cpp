#include "Rectangle.h"

Rectangle::Rectangle(double sideOne, double sideTwo) : Shape(sideOne) {
	setSecondSide(sideTwo);
}

void Rectangle::setSecondSide(double side) {
	while (side < 0) {
		std::cout << "The side must be a poditive number. ";
		std::cin >> side;
	}

	this->_secondSide = side;
}

double Rectangle::getSecondSide() const {
	return this->_secondSide;
}

void Rectangle::draw() {
	std::cout << "\nRectangle is drawing...\n";
	std::cout << "Calling from Rectangle: " << std::endl;
	Shape::draw();
}
