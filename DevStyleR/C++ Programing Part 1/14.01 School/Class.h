#pragma once

#include "Teacher.h"
#include "Student.h"

class Class {
public:
	Class(std::string&, std::vector<Teacher>&, std::vector<Student>&);

	std::string getIdentifier();
	std::vector<Teacher> getTeachers();
	std::vector<Student> getStudents();

private:
	std::string identifier;
	std::vector<Teacher> teachers;
	std::vector<Student> students;
};
