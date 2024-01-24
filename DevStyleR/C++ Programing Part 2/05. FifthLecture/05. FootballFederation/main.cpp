#include "User.h"
#include "Team.h"
#include"Admin.h"
#include "Schedule.h"

int main() {
    // Create admin
    Admin a1("Zahari", "pass1");

    // Create teams
    Team team1("Ral Madrid", "Madrid");
    Team team2("Inter", "Milan");
    Team team3("Liverpool", "Liverpool");

    // Add teams
    std::cout << "Number of teams: " << a1.getTeams().size() << std::endl;
    a1.addTeam(team1);
    a1.addTeam(team2);
    a1.addTeam(team3);
    std::cout << "\n" << "Number of teams: " << a1.getTeams().size() << std::endl;

    // remove team
    //a1.removeTeam(team2);
    //std::cout << "Number of teams: " << a1.getTeams().size() << std::endl;

    // Update team
    //Team team4("Slavia", "Plovdiv");
    //a1.updateTeam(team4);

    // Show all teams
    for (auto& t : a1.getTeams()) {
        std::cout << t.getName() << " - " << t.getCity() << std::endl;
    }

    std::cout << std::endl;

    Schedule schedule;
    schedule.addMatch(&a1, 1, &team1, &team2);
    schedule.addMatch(&a1, 1, &team1, &team3);
    schedule.addMatch(&a1, 5, &team3, &team2);
    schedule.addMatch(&a1, 0, &team2, &team1);
    schedule.addMatch(&a1, 4, &team3, &team1);
    schedule.addMatch(&a1, 6, &team2, &team3);
    schedule.printSchedule();

    schedule.updateMatch(&a1, 2, &team3, &team1);
    schedule.updateMatch(&a1, 5, &team1, &team3);

    schedule.deleteMatch(&a1, 2);

    schedule.addMatch(&a1, 7, &team3, &team1);
    schedule.printSchedule();

    return 0;
}
