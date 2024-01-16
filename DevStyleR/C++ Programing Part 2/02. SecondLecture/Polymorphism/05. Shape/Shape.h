#pragma once

#include <iostream>

class Shape {
public:
	Shape(int);

	virtual int getArea();
	int getA();

	void setA(int);

	virtual void print();

private:
	int a;
};
