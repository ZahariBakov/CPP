#pragma once

#include "Drinks.h"

class Alcoholic : public Drinks {
public:
	Alcoholic(std::string, double, int, std::string, double, int);

	void setVolume(double);
	void setTax(int);

	double getVolume();
	int    getTax();

	void   print();
	double calculatePrice();

private:
	double _volume;
	int _tax;
};
