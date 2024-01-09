#include "Discipline.h"

Discipline::Discipline(std::string name, int lNumbers, int eNumbers) {
	this->name = name;
	this->lectureCount = lNumbers;
	this->exerciseCount = eNumbers;
}

void Discipline::printDisciplineIfno() {
	std::cout << this->name << " " << this->lectureCount << " " << this->exerciseCount;
}
