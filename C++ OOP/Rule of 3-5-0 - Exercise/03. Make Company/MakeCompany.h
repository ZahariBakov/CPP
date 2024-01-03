#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include <memory>
#include <vector>
#include <string>

#include "Company.h"

enum CompanyFields {
	ID_IDX,
	NAME_IDX,
	EMPLOYEES_IDX
};

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& properties) {
	const int id = std::stoi(properties[ID_IDX]);
	const std::string name = properties[NAME_IDX];
	std::vector<std::pair<char, char>> employees;

	const size_t propertiesCount = properties.size();
	std::string employeeStr;

	for (size_t i = EMPLOYEES_IDX; i < propertiesCount; ++i) {
		employeeStr = properties[i];
		employees.emplace_back(employeeStr[0], employeeStr[1]);
	}

	// C++ 11
	std::shared_ptr<Company> result = std::make_shared<Company>(id, name, employees);

	// C++ 14
	//std::shared_ptr<Company> result = std::make_unique<Company>(id, name, employees);

	return result;
}

#endif // !MAKE_COMPANY_H