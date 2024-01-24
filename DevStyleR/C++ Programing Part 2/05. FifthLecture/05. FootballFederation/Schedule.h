#pragma once

#include "Admin.h"
#include "Referee.h"

#include <map>

class Schedule {
public:
	void addMatch(Admin*, int, Team*, Team*);
	void updateMatch(Admin*, int, Team*, Team*);
	void deleteMatch(Admin*, int);

	void addReferee(Admin*, int, std::string);
	void addResult(Referee*, Team*, Team*);

	void printSchedule();

private:
	std::map<int, std::pair<Team*, Team*>> _matches;
	std::map<int, std::pair<int, int>> _matchResults;
	std::map<int, std::string> _refereeMatches;
	std::map<int, std::string, std::greater<int>> _ranking;
};
