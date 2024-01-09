#include "Teacher.h"

Teacher::Teacher(std::string &name, std::string title, std::vector<Discipline> &disciple)
	: name(name), title(title), disciplines(disciple) {}

std::string Teacher::getName() { 
	return this->name; 
}

std::string Teacher::getTitle() { 
	return this->title;
}

std::vector<Discipline> Teacher::getDisciplines() {
	return this->disciplines;
}


//void Teacher::printTeacherInfo() {
//	std::cout << "Teacher name " << this->name << " title " << this->title << " and discipline ";
//	this->disciplines.printDisciplineIfno();
//	std::cout << std::endl;
//}
