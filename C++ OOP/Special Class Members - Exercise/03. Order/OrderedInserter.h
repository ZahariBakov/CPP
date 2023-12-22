#ifndef ORDERED_INSERTER_H
#define ORDERED_INSERTER_H

#include "Company.h"

class OrderedInserter {
public:
	OrderedInserter(std::vector<const Company*>& vec)
		: vec(vec) {}

	void insert(const Company* company) {
		auto insertIterator = vec.begin();

		while (insertIterator != vec.end() && 
			company->getId() > (*insertIterator)->getId()) {
				insertIterator++;
		}

		vec.insert(insertIterator, company);
	}

private:
	std::vector<const Company*>& vec;
};

#endif // !ORDERED_INSERTER_H
