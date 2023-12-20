#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <sstream>

bool tryParse(std::string string, int& num) {
	std::istringstream istr(string);

	bool parsedSuccess = (bool)(istr >> num);

	return parsedSuccess;
}

#endif // !TRY_PARSE_H
