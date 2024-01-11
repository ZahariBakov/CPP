#pragma once

#include <iomanip>

#include "Vector2D.h"

class Shape {
public:
	Shape(const Vector2D& center);
	Shape();

	Vector2D getCenter() const;

	double getArea() const;

protected:
	double area;
private:
	Vector2D _center;
};
