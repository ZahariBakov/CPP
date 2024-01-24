#pragma once

#include "Admin.h"

#include <map>

class Schedule {
public:
	void addMatch(int, Team*, Team*);

	void printSchedule();

private:
	std::map<int, std::pair<Team*, Team*>> _matches;
};
