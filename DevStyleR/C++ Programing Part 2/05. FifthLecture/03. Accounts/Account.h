#pragma once

#include <iostream>

class Account {
public:
	Account(double);

	void setMoney(double);

	double getMoney();

	virtual double debit(double);
	virtual double credit(double);
	virtual double getBalance();

private:
	double _money;
};
