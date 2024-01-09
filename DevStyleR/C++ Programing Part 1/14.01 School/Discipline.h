#pragma once

#include <iostream>
#include <string>

class Discipline {
public:
	Discipline(std::string, int, int);
	void printDisciplineIfno();

private:
	std::string name;
	int lectureCount;
	int exerciseCount;
};
