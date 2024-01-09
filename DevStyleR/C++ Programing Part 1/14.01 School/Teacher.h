#pragma once

#include "Discipline.h"

class Teacher {
public:
	Teacher(std::string&, std::string, std::vector<Discipline>&);

	std::string getName();
	std::string getTitle();
	std::vector<Discipline> getDisciplines();

	//void printTeacherInfo();

private:
	std::string name;
	std::string title;
	std::vector<Discipline> disciplines;
};
