#pragma once

#include "Order.h"

class User {
public:
	User(std::string);

	void setUserName(std::string);

	std::string getUserName();

private:
	std::string _userName;
};
