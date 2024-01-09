#pragma once

#include <iostream>
#include <string>

class Student {
public:
	Student(std::string, int);

	void setName(std::string);
	void setId(int);

	std::string getName();
	int getId();

	void printStudentInfo();

private:
	std::string name;
	int id;
};
