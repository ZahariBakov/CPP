#pragma once

#include "Shape.h"

class Rectangle : public Shape {

public:

	Rectangle(double, double);

	void setSecondSide(double);

	double getSecondSide() const;

	void draw() override;

private:
	double _secondSide;
};
