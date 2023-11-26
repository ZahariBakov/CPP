#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <array>
#include <algorithm>

const int CITY_IDX = 0;
const int LATITUDE_IDX = 1;
const int LONGITUDE_IDX = 2;
const int ATTRIBUTES_COUNT = 3;
const std::string lineDelimiter = ".";
const char attributeDelimiter = ',';

std::vector<std::array<std::string, ATTRIBUTES_COUNT>> readCityAttributesFromInput() {
	std::vector<std::array<std::string, ATTRIBUTES_COUNT>> attributes;
	std::string line;

	std::array<std::string, ATTRIBUTES_COUNT> currAttributes;
	while (true) {
		getline(std::cin, line);

		if (line == lineDelimiter) {
			break;
		}

		std::istringstream istr(line);
		getline(istr, currAttributes[CITY_IDX], attributeDelimiter);
		getline(istr, currAttributes[LATITUDE_IDX], attributeDelimiter);
		getline(istr, currAttributes[LONGITUDE_IDX], attributeDelimiter);
		attributes.push_back(currAttributes);
	}

	return attributes;
}

std::vector<std::string> readQueriesFromInput() {
	std::vector<std::string> queries;
	std::string query;

	while (true) {
		getline(std::cin, query);

		if (query == lineDelimiter) {
			break;
		}

		queries.push_back(query);
	}

	return queries;
}

std::unordered_map<std::string, std::string> constructCityMap(
								      const std::vector<std::array<std::string, ATTRIBUTES_COUNT>>& attributes) {
	std::unordered_map<std::string, std::string> cityMap;

	std::string currCoordsStringified;
	for (const auto& currAttribute : attributes) {
		currCoordsStringified = currAttribute[LATITUDE_IDX];
		currCoordsStringified.append(",").append(currAttribute[LONGITUDE_IDX]);
		cityMap[currAttribute[CITY_IDX]] = currCoordsStringified;
	}

	return cityMap;
}

std::unordered_map<std::string, std::vector<std::string>> constructCoordsMap(
								       const std::vector<std::array<std::string, ATTRIBUTES_COUNT>>& attributes) {
	std::unordered_map<std::string, std::vector<std::string>> coordsMap;

	std::string currCoordsStringified;
	for (const auto& currAttribute : attributes) {
		currCoordsStringified = currAttribute[LATITUDE_IDX];
		currCoordsStringified.append(",").append(currAttribute[LONGITUDE_IDX]);
		coordsMap[currCoordsStringified].push_back(currAttribute[CITY_IDX]);
	}

	return coordsMap;
}

bool isCoordinate(const std::string& input) {
	double temp;
	int count = 0;
	std::istringstream istr(input);

	while (istr >> temp) {
		++count;
	}

	return 2 == count;
}

bool isCityQuery(std::string& query) {
	std::istringstream istr(query);
	const char delimiter = ' ';
	std::string placeholder;
	getline(istr, placeholder, delimiter);

	if (getline(istr, placeholder, delimiter) && !placeholder.empty()) {
		return false;
	}

	return true;
}

std::string executeCityQuery(const std::unordered_map<std::string, std::string>& cityMap,
			   std::string& query) {
	std::string result;
	auto it = cityMap.find(query);

	if (it == cityMap.end()) {
		std::cerr << "Error, query for city: " << query << " not found in map." << std::endl;
		return result;
	}

	result = it->first;
	result.append(",").append(it->second).append("\n");

	return result;
}

std::string executeCoordsQuery(const std::unordered_map<std::string, std::vector<std::string>>& coordsMap,
							   std::string& query) {
	std::string result;
	const std::string processedQuery = [&query]() {
		std::string processedQuery = query;
		std::replace(processedQuery.begin(), processedQuery.end(), ' ', ',');
		return processedQuery;
	}(); // Immediately invoked lambda expression with this () in end.

	const auto it = coordsMap.find(processedQuery);

	if (it == coordsMap.end()) {
		std::cerr << "Error, query for coord: " << query << " not found in map." << std::endl;
		return result;
	}

	const auto& coords = it->first;
	const auto& cities = it->second;

	for (const auto& city : cities) {
		result.append(city).append(",").append(coords).append("\n");
	}

	return result;
}

std::string executeSingleQuery(const std::unordered_map<std::string, std::string>& cityMap,
	const std::unordered_map<std::string, std::vector<std::string>>& coordsMap,
	std::string& query) {
	std::string result;
	const bool isCity = !isCoordinate(query);
	if (isCity) {
		result = executeCityQuery(cityMap, query);
	}
	else {
		result = executeCoordsQuery(coordsMap, query);
	}

	return result;
}

std::vector<std::string> executeQueries(const std::unordered_map<std::string, std::string>& cityMap,
										const std::unordered_map<std::string, std::vector<std::string>>& coordsMap,
									    std::vector<std::string> queries) {
	const size_t queriesSize = queries.size();
	std::vector<std::string> results(queriesSize);


	for (size_t i = 0; i < queriesSize; ++i) {
		results[i] = executeSingleQuery(cityMap, coordsMap, queries[i]);
	}

	return results;
}

void printResults(const std::vector<std::string>& results) {
	for (const auto& result : results) {
		std::cout << result;
	}
}

int main() {
	const auto cityAttributes = readCityAttributesFromInput();
	const auto queries = readQueriesFromInput();
	const auto cityMap = constructCityMap(cityAttributes);
	const auto coordsMap = constructCoordsMap(cityAttributes);
	const auto results = executeQueries(cityMap, coordsMap, queries);
	printResults(results);

	return 0;
}
