#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <string>
#include <sstream>

template<typename T>
T parse(std::string s) {
	std::istringstream istr(s);
	T t;
	istr >> t;

	return t;
}

template<typename T>
std::vector<T> split(std::string s, char separator) {
	std::istringstream istr(s);
	std::string itemStr;

	std::vector<T> items;

	while (std::getline(istr, itemStr, separator)) {
		items.push_back(parse<T>(itemStr));
	}

	return items;
}

#endif // !SPLIT_H

