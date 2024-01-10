#pragma once

#include <string>

class Car;

class Wheel {
public:
	Wheel(int angle, Car* car);

	void turn(int angle);

	std::string toString() const;

private:
	int _angle;
	Car* _car;
};
