#pragma once

#include "Order.h"

class User {
public:
	User(std::string, std::vector<Order>&);

	void setUsername(std::string);

	std::string getUsername();

	void printBill();

private:
	std::string _username;
	std::vector<Order> _orders;
};
