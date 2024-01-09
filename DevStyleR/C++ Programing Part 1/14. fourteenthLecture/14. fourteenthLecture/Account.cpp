#include "Account.h"

#include <iostream>

Account::Account(unsigned balance) {
	if (balance >= 0) {
		this->balance = balance;
	}
	else {
		this->balance = 0;
		std::cerr << "Invalid initial balance" << std::endl;
	}
}

void Account::credit(unsigned amount) {
	if (amount > 0) {
		this->balance += amount;
	}
	else {
		std::cout << "Invalid amount." << std::endl;
	}
}

void Account::debit(unsigned amount) {
	if (amount <= balance) {
		this->balance -= amount;
	}
	else {
		std::cout << "Debit amount exceeded account balance." << std::endl;
	}
}

unsigned Account::getBalance() {
	return this->balance;
}
