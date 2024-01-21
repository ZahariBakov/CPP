#pragma once

#include "Account.h"

class CheckingAccount : public Account {
public:
	CheckingAccount(double);

	double debit(double);
	double credit(double);
	double getBalance();
	double calculateInterest();
};
