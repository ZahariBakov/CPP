#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <iostream>
#include <vector>
#include <string>

const std::vector<std::string> operator + (const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
	std::vector<std::string> vecResult;

	std::string temp;

	for (int i = 0; i < vec1.size(); ++i) {
		temp = vec1[i] + " " + vec2[i];
		vecResult.push_back(temp);
	}

	return vecResult;
}

#endif // !SUMOFVECTORS_H