#include "Teacher.h"

Teacher::Teacher(std::string name, std::string title, Discipline& disciple) 
	: name(name), title(title), discipline(disciple) {}

void Teacher::printTeacherInfo() {
	std::cout << "?eacher name " << this->name << " title " << this->title << " and discipline "; 
	this->discipline.printDisciplineIfno();
}
