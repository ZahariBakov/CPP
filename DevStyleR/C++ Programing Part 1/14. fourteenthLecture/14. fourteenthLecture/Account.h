#pragma once

class Account {
public:
	Account(unsigned);
	void credit(unsigned);
	void debit(unsigned);
	unsigned getBalance();

private:
	unsigned int balance;
};
