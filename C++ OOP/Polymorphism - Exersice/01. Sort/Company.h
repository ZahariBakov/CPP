#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <sstream>
#include <vector>
#include <utility>

class Company {

public:
	Company() {}

	Company(int id, std::string name) : id(id), name(name) {}

	std::string toString() {
		std::ostringstream stream;
		stream << name << " " << id;

		return stream.str();
	}

	std::string getName() const {
		return this->name;
	}

	int getId() const {
		return this->id;
	}

private:
	int id;
	std::string name;
};

#endif // !COMPANY_H
