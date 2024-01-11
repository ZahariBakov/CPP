#include "Shape.h"

Shape::Shape(const Vector2D& center) : area(0), _center(center) {}

Shape::Shape() : area(0), _center(0, 0) {}

Vector2D Shape::getCenter() const {
	return _center;
}

double Shape::getArea() const {
	return area;
}
