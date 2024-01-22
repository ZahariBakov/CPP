#pragma once

#include "Order.h"
#include "User.h"

class Shop {
public:
	Shop(std::vector<User*>);

	void soldDrinks();
	void bestClient();
	void searchByDrinks(std::string);
	//void searchByDrinksAndMoney();

private:
	std::vector<User*> _users;
};
