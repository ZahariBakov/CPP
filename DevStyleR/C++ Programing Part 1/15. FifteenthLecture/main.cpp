#include <iostream>

#include "Screening.h"
#include "Hall.h"

int main() {
    Screening sc1("Star Wars", 100);
    Screening sc2("The Godfather", 75);

    std::vector<Screening> screenings;
    screenings.push_back(sc1);
    screenings.push_back(sc2);

    Hall h1("Hall 8", 250, screenings);
    h1.print();


    Hall h2("Hall 2", 125, screenings);
    h2.print();

    Screening sc3("Indian Jones", 50);
    Screening sc4("Dune 2", 33);

    std::vector<Screening> screening2;
    screening2.push_back(sc3);
    screening2.push_back(sc4);


    Hall h3("Hall 10", 500, screening2);
    h3.print();

    Screening sc5("Nemo 2", 55);
    h3.addScreening(sc5);
    h3.print();

    return 0;
}
