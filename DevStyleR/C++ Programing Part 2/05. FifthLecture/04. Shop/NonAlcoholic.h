#pragma once

#include "Drinks.h"

class NonAlcoholic : public Drinks {
public:
	NonAlcoholic(std::string, double, int, std::string, double, int);

	void setLiters(double);
	void setCityTax(int);

	double getLiters();
	int    getCityTax();

	void   print();
	double calculatePrice();

private:
	double _liters;
	int _cityTax;
};
