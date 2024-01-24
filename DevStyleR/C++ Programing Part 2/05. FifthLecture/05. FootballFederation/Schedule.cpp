#include "Schedule.h"

static int findFreeDay(std::map<int, std::pair<Team*, Team*>> matches) {
	int freeDay = 1;

	std::map<int, std::pair<Team*, Team*>>::iterator it = matches.begin();

	while (it != matches.end()) {
		if (freeDay != it->first) {
			break;
		}

		freeDay++;
		it++;
	}

	return freeDay;
}

void Schedule::addMatch(int day, Team* host, Team* guest) {
	int lastDay = 0;

	for (auto& match : this->_matches) {
		lastDay = match.first;
		if (day == match.first) {
			std::cout << day << " day is already taken. \n";
			day = findFreeDay(this->_matches);
			std::cout << "Day is set to " << day << std::endl;
		}
		else if (day <= 0) {
			std::cout << day << " day must be positive number greater than 0. \n";
			day = findFreeDay(this->_matches);
			std::cout << "Day is set to " << day << std::endl;
		}
	}

	if (day > lastDay + 1) {
		std::cout << day << " day is too larger number." << std::endl;
		day = findFreeDay(this->_matches);
		std::cout << "Day is set to " << day << std::endl;
	}
	this->_matches[day] = std::make_pair(host, guest);
}

void Schedule::printSchedule() {
	std::cout << "\n              --- Schedule ---" << std::endl;
	for (auto& match : this->_matches) {
		std::cout << "Day: " << match.first << " Current match is: " << match.second.first->getName() << " - " << match.second.second->getName() << "\n";
	}
	std::cout << std::endl;
}
