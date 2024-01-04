#ifndef ARRAY_OF_POINTERS_H_
#define ARRAY_OF_POINTERS_H_

#include "Company.h"


class ArrayOfPointers {
	std::vector<std::shared_ptr<Company> > pointers;
public:
	ArrayOfPointers() {}

	void add(Company* c) {
		this->pointers.push_back(std::shared_ptr<Company>(c));
	}

	int getSize() const {
		return this->pointers.size();
	}

	Company* get(int index) const {
		return this->pointers.at(index).get();
	}
};

#endif // !ARRAY_OF_POINTERS_H_
