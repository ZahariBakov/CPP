#pragma once

#include "Admin.h"

#include <map>

class Schedule {
public:
	void addMatch(Admin*, int, Team*, Team*);
	void updateMatch(Admin*, int, Team*, Team*);
	void deleteMatch(Admin*, int);

	void printSchedule();

private:
	std::map<int, std::pair<Team*, Team*>> _matches;
};
