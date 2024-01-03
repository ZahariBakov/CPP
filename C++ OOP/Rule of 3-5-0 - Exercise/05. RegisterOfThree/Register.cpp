#include <iostream>
#include <algorithm>

#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {

}

void Register::add(const Company& c) {
	companiesArray[numAdded] = c;
	++numAdded;
}

Company Register::get(int companyId) const {
	//for (size_t i = 0; i < numAdded; ++i) {
	//	if (companyId == companiesArray[i].getId()) {
	//		return companiesArray[i];
	//	}
	//}

	auto begin = companiesArray;
	auto end = companiesArray + numAdded;

	const auto it = std::find_if(begin, end, [companyId](const Company& c) {
		return c.getId() == companyId;
		});

	if (it != end) {
		return *it;
	}

	std::cerr << "Company with Id: " << " was not found.";
	return Company();
}

Register::~Register() {
	if (companiesArray) {
		delete[] companiesArray;
		companiesArray = nullptr;
	}
}

Register& Register::operator=(const Register& other) {
	if (this != &other) {
		Company* companies = new Company[other.numAdded];

		std::copy(other.companiesArray, other.companiesArray + other.numAdded, companies);

		numAdded = other.numAdded;

		if (companiesArray) {
			delete[] companiesArray;
		}

		companiesArray = companies;
		companies = nullptr;
	}

	return *this;
}

Register::Register(const Register& other)
	: numAdded(other.numAdded), companiesArray(new Company[numAdded]) {
	std::copy(other.companiesArray, other.companiesArray + other.numAdded, companiesArray);
}