#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

void readInput(int n, 
    std::map < std::string, std::map<std::string, std::vector<std::string> > >& continentData,
    std::map<std::string, std::vector<std::string> >& countriesData,
    std::vector<std::string>& continents,
    std::vector<std::string>& countries) {

    std::vector<std::string> cities;

    for (int i = 0; i < n; ++i) {
        std::string continent, country, city;
        std::cin >> continent >> country >> city;

        if (continentData.find(continent) == continentData.end()) {
            continentData[continent] = countriesData;
            continents.push_back(continent);

            if (countriesData.find(country) == countriesData.end()) {
                countriesData[country] = cities;
                countries.push_back(country);
            }

            countriesData[country].push_back(city);
        } 
    }
}

void printSolution(std::map < std::string, std::map<std::string, std::vector<std::string> > >& continentData,
    std::map<std::string, std::vector<std::string> >& countriesData,
    std::vector<std::string>& continents,
    std::vector<std::string>& countries) {

    std::string continent;
    std::string country;
    std::vector<std::string> cities;
    std::string city;

    for (int c = 0; c < continents.size(); ++c) {
        continent = continents[c];
        std::cout << continent << ":" << std::endl;

        auto data = continentData[continent];

        for (int i = 0; i < countries.size(); ++i) {
            country = countries[i];
            std::cout << country << " -> ";

            cities = countriesData[country];

            for (int y = 0; y < cities.size(); ++y) {
                std::cout << cities[y] << ", ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int entriesNumber;
    std::cin >> entriesNumber;

    std::map < std::string, std::map<std::string, std::vector<std::string> > > continentData;
    std::map<std::string, std::vector<std::string> > countriesData;
    std::vector<std::string> continents;
    std::vector<std::string> countries;

    readInput(entriesNumber, continentData, countriesData, continents, countries);

    printSolution(continentData, countriesData, continents, countries);

    return 0;
}
