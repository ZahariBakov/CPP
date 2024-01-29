#include "Circle.h"

Circle::Circle(double side) : Shape(side) {}

void Circle::draw() {
	std::cout << "\nCircle is drawing...\n";
	std::cout << "Calling from Circle: " << std::endl;
	Shape::draw();
}
