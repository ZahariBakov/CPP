#include "User.h"
#include "Team.h"
#include"Admin.h"

int main() {
    Admin a1("Zahari", "pass1");

    Team team1("Levski", "Sofia");
    Team team2("CSKA", "Sofia");
    Team team3("Slavia", "Sofia");

    
    std::cout << "Teams count: " << a1.getTeams().size() << std::endl;
    a1.addTeam(team1);
    a1.addTeam(team2);
    a1.addTeam(team3);
    std::cout << "Teams count: " << a1.getTeams().size() << std::endl;
    a1.removeTeam(team2);

    std::cout << "Teams count: " << a1.getTeams().size() << std::endl;

    Team team4("Slavia", "Plovdiv");
    a1.updateTeam(team4);

    for (auto t : a1.getTeams()) {
        std::cout << "Teams count: " << t.getName() << " " << t.getCity() << std::endl;
    }

    return 0;
}
