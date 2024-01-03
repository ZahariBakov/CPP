#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include <unordered_set>

#include "Company.h"

Company* parseUniqueCompanies(const std::string &input, int& numCompanies, std::string(*filter)(const Company&)) {
	std::istringstream istr(input);
	std::unordered_set<std::string> uniqueCompaniesStr;
	std::string name;
	int id = 0;
	std::vector<Company> comapnies;

	while (istr >> id >> name) {
		Company c(id, name);
		const std::string uniqueFilter = filter(c);

		const auto it = uniqueCompaniesStr.find(uniqueFilter);
		if (it == uniqueCompaniesStr.end())  {
			uniqueCompaniesStr.insert(uniqueFilter);
			comapnies.emplace_back(id, name);
		}
	}
	
	const size_t comapniesCount = comapnies.size();
	numCompanies = static_cast<int>(comapniesCount);
	Company* companiesRawArray = new Company[comapniesCount];

	for (size_t i = 0; i < comapniesCount; ++i) {
		companiesRawArray[i] = comapnies[i];
	}

	return companiesRawArray;
}

#endif // !PARSE_COMPANIES_H