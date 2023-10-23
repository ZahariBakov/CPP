#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

void replaceComma(std::string& str, char replacer) {
    std::replace(str.begin(), str.end(), ',', replacer);
}

void readUserCoordinates(std::string& userLon, std::string& userLat) {
    std::cin >> userLon;
    std::cin.ignore();
    std::cin >> userLat;
    std::cin.ignore();

    replaceComma(userLon, '.');
    replaceComma(userLat, '.');
}

std::vector<std::string> readDefibrilatorDataFormInput() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::string> defib(n);

    for (int i = 0; i < n; i++) {
        getline(std::cin, defib[i]);
    }

    return defib;
}

void parseDefibData(const std::vector<std::string>& defsData,
                    std::vector<std::string>& defNumbers,
                    std::vector<std::string>& defNames,
                    std::vector<std::string>& defAdress,
                    std::vector<std::string>& defPhone,
                    std::vector<std::string>& defLons,
                    std::vector<std::string>& defLats) {
    const size_t size = defsData.size();
    defNumbers.resize(size);
    defNames.resize(size);
    defAdress.resize(size);
    defPhone.resize(size);
    defLons.resize(size);
    defLats.resize(size);

    std::istringstream istr;
    const char delimiter = ';';

    for (size_t i = 0; i < size; ++i) {
        istr.clear();
        istr.str(defsData[i]);
        getline(istr, defNumbers[i], delimiter);
        getline(istr, defNames[i], delimiter);
        getline(istr, defAdress[i], delimiter);
        getline(istr, defPhone[i], delimiter);
        getline(istr, defLons[i], delimiter);
        getline(istr, defLats[i], delimiter);

        replaceComma(defLons[i], '.');
        replaceComma(defLats[i], '.');
    }
}

std::vector<double> getDistances(const std::string& userLon,
                                 const std::string& userLat,
                                 const std::vector<std::string>& defLons,
                                 const std::vector<std::string>& defLats) {
    size_t size = defLons.size();
    std::vector<double> distances(size);
    const double userLonD = std::stod(userLon);
    const double userLatD = std::stod(userLat); 
    const double earthRadius = 6371;

    for (size_t i = 0; i < size; ++i) {
        const double defLonD = std::stod(defLons[i]);
        const double defLatD = std::stod(defLats[i]);

        const double x = (defLonD - userLonD) * cos((defLonD + userLonD) / 2.0);
        const double y = (defLatD - userLatD);
        const double currDistance = sqrt((x * x) + (y * y)) * earthRadius;
        distances[i] = currDistance;
    }

    return distances;
}

size_t getClosestIndex(const std::vector<double>& distances) {
    return (std::min_element(distances.begin(), distances.end()) - distances.begin());
}

void printSolution(const std::vector<std::string>& defNames, size_t minIndex) {
    std::cout << defNames[minIndex] << std::endl;
}

int main()
{
    std::string userLon;
    std::string userLat;

    readUserCoordinates(userLon, userLat);
    const std::vector<std::string> defsData = readDefibrilatorDataFormInput();

    std::vector<std::string> defNumbers;
    std::vector<std::string> defNames;
    std::vector<std::string> defAdress;
    std::vector<std::string> defPhone;
    std::vector<std::string> defLons;
    std::vector<std::string> defLats;

    parseDefibData(defsData, defNumbers, defNames, defAdress, defPhone, defLons, defLats);

    const std::vector<double> distances = getDistances(userLon, userLat, defLons, defLats);

    const size_t minIndex = getClosestIndex(distances);

    printSolution(defNames, minIndex);

    return 0;
}
