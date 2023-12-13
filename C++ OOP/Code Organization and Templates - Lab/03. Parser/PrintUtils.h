#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <vector>
#include <iostream>

template<typename T>
void printVector(std::vector<T> v) {
	for (T& element : v) {
		std::cout << element << " ";
	}
}

#endif // !PRINTUTILS_H

