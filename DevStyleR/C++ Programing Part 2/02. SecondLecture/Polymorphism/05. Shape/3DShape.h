#pragma once

#include "Shape.h"

class ThreeDShape : public Shape {
public:
	ThreeDShape(int, int);

	int getArea();
	int getVolume();
	int getH();

	void setH(int);

	void print();

private:
	int h;
};
