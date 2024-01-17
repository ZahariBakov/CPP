#pragma once

#include "2DShape.h"

class Rectangle : public TwoDShape {
public:
	Rectangle(int, int);

	double getArea();
	int getB();

	void setB(int);

	void position();
	bool fill();
	void draw();

	void print();

private:
	int b;
};
