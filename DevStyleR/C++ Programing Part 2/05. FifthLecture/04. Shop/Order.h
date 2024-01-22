#pragma once

#include "Alcoholic.h"
#include "NonAlcoholic.h"

#include <vector>

class Order {
public:
	static int number;

	Order(std::vector<Drinks*>, std::string);

	void   setNumber(int);
	void   setDate(std::string);
	void   setTotalPrice(double);

	int         getNumber();
	std::string getDate();
	double      getTotalPrice();
	std::vector<Drinks*> getDrinks();

	double calculateTotalPrice();
	void   printOrder();

private:
	int                  _number;
	std::vector<Drinks*> _drinks;
	std::string          _date;
	double               _totalPrice;
};
