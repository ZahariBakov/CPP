#pragma once

#include "Discipline.h"

class Teacher {
public:
	Teacher(std::string, std::string, Discipline&);
	void printTeacherInfo();

private:
	std::string name;
	std::string title;
	Discipline discipline;
};
