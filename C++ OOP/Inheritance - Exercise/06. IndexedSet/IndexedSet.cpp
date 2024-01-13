#include "IndexedSet.h"

#include <algorithm>

// Constructor:
IndexedSet::IndexedSet() : valuesArray(nullptr) {}

// Destructor:
IndexedSet::~IndexedSet() {
	if (valuesArray) {
		//delete[] valuesArray;
		//valuesArray = nullptr;
		clearIndex();
	}
}

 // Copy-constructor:
IndexedSet::IndexedSet(const IndexedSet& other) : valuesArray(nullptr) {
	valuesSet = other.valuesSet;

	if (other.valuesArray) {
		const size_t size = other.valuesSet.size();
		valuesArray = new Value[size];
		std::copy(other.valuesArray, other.valuesArray + size, valuesArray);
		//             begin               end                    where
	}
}

// copy-assignment operator:
IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
	if (this != &other) {
		clearIndex();

		valuesSet = other.valuesSet;

		if (!valuesSet.empty()) {
			buildIndex();
		}
	}

	return *this;
}

// functions:
void IndexedSet::add(const Value& v) {
	// 1 2 7 149
	// has buildIndex
	// add 168
	clearIndex();
	valuesSet.insert(v);
}

size_t IndexedSet::size() const {
	return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
	if (nullptr == valuesArray) {
		buildIndex();
	}

	return valuesArray[index];
}

void IndexedSet::buildIndex() {
	const size_t size = valuesSet.size();
	valuesArray = new Value[size];

	size_t idx = 0;
	for (const auto value : valuesSet) {
		valuesArray[idx] = value;
		++idx;
	}
}

void IndexedSet::clearIndex() {
	if (valuesArray) { // sanity check
		delete[] valuesArray;
		valuesArray = nullptr;
	}
}
