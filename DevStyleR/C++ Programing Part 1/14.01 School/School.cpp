#include "School.h"

School::School(std::vector<Class>& c) : classes(c) {}

std::vector<Class> School::getClasses() {
	return this->classes;
}
