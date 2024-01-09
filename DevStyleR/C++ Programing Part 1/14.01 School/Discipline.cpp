#include "Discipline.h"

Discipline::Discipline(std::string name, int lectures, int exercises) {
	setName(name);
	setLecturesNumber(lectures);
	setExercisesNumber(exercises);
}

std::string Discipline::getName() {
	return this->name;
}

int Discipline::getLectures() {
	return this->lectureCount;
}

int Discipline::getExrcises() {
	return this->exerciseCount;
}

void Discipline::printDisciplineIfno() {
	std::cout << this->name << " " << this->lectureCount << " " << this->exerciseCount;
}
