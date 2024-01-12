#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal(string, string, int);

	void setName(string);
	void setKind(string);
	void setYear(int);

	string getName();
	string getKind();
	int	   getYear();

	void print();

private:
	string kind;
	string name;
	int year;
};

