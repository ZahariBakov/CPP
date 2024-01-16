#include "2DShape.h"

TwoDShape::TwoDShape(int a) : Shape(a) {}

int TwoDShape::getArea() {
	std::cout << "In 2D getArea" << std::endl;

	return 0;
}

void TwoDShape::print() {
	std::cout << "In 2D print" << std::endl;

	Shape::print();
}
