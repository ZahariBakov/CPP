#include "Student.h"

Student::Student(std::string name, int id) {
	setName(name);
	setId(id);
}

void Student::setName(std::string name) {
	this->name = name;
}

void Student::setId(int id) {
	this->id = id;
}

void Student::printStudentInfo() {
	std::cout << "Student name " << this->name << " and id " << this->id << std::endl;
}
