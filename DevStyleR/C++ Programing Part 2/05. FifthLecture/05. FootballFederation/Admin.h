#pragma once

#include <vector>

#include "User.h"
#include "Team.h"

class Admin : public User {
public:
	Admin(std::string, std::string);

	void addTeam(Team);
	void removeTeam(Team);
	void updateTeam(Team);

	std::vector<Team> getTeams();

private:
	std::vector<Team> _teams;
};
