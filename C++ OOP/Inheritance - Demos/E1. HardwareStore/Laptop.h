#pragma once

#include <iostream>

#include "Hardaware.h"

class Laptop : public Hardware {
public:
	Laptop() = delete;

	Laptop(const std::string& name,
		   const double       price,
		   const double       monitorSize);

	virtual ~Laptop();

	Laptop(const Laptop& other);

	Laptop& operator=(const Laptop& other);

private:
	void printInfo() {
		std::cout << "Model: " << getName() << ", price: " << getPrice()
			<< ", monitorSize: " << _monitorSize;
	}

	double _monitorSize;
};
