#pragma once

#include <iostream>

class Shape {

public:

	Shape(double);

	void setFirstSide(double);

	double getfisrtSide() const;

	virtual void draw();

private:

	double _firstSide;
};
