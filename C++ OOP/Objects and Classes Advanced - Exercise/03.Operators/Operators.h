#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::ostream& operator<< (std::ostream& output, const std::vector<std::string>& input) {
	for (std::string elem : input) {
		output << elem << std::endl;
	}

	return output;
}

std::vector<std::string>& operator<<(std::vector<std::string>& out, const std::string& s) {
	out.push_back(s);

	return out;
}

std::string operator + (std::string string, int input) {
	std::ostringstream result;

	result << string << input;

	return result.str();
}

#endif // !OPERATORS_H