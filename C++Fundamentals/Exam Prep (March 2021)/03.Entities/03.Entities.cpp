#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> readSingleLineFromInput() {
    std::vector<std::string> vec;
    std::string line;
    getline(std::cin, line);
    std::istringstream istr(line);

    std::string word;

    while (istr >> word) {
        vec.push_back(word);
    }

    return vec;
}

std::vector<std::vector<std::string>> readDataBase(size_t numberOfColumns) {
    std::vector<std::vector<std::string>> db(numberOfColumns);
    std::vector<std::string> currentLine;

    while (true) {
        currentLine = readSingleLineFromInput();

        if (currentLine[0] == "end") {
            break;
        }

        for (size_t i = 0; i < numberOfColumns; ++i) {
            db[i].push_back(currentLine[i]);
        }
    }

    return db;
}

size_t findHeaderIndex(const std::vector<std::string>& header,
                       const std::string& query) {
    std::vector<std::string>::const_iterator it = std::find(header.begin(), header.end(), query);

    return it - header.begin();
}

void printMostCommonElement(std::vector<std::string>& searchedColumn) {
    std::sort(searchedColumn.begin(), searchedColumn.end());

    int maxCount = 1;
    int currCount = 1;
    size_t maxCountIndex = 0;
    const size_t size = searchedColumn.size();

    for (size_t i = 1; i < size; ++i) {

        if (searchedColumn[i - 1] == searchedColumn[i]) {
            ++currCount;

            if (currCount > maxCount) {
                maxCount = currCount;
                maxCountIndex = i;
            }
        }
        else {
            currCount = 1;
        }
    }

    std::cout << searchedColumn[maxCountIndex] << " " << maxCount << std::endl;
}

void printMostCommonElement(const std::vector<std::vector<std::string>>& db,
                            const std::vector<std::string>& header, 
                            const std::string& query) {
    const size_t headerIndex = findHeaderIndex(header, query);
    std::vector<std::string> searchedColumn = db[headerIndex];

    printMostCommonElement(searchedColumn);
}

int main() {
    const std::vector<std::string> header = readSingleLineFromInput();
    const std::vector<std::vector<std::string>> db = readDataBase(header.size());
    const std::string query = readSingleLineFromInput()[0];

    printMostCommonElement(db, header, query);

    return 0;
}
