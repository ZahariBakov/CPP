#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <iterator>

int readStudentsNumber() {
    int n;
    std::cin >> n;

    return n;
}

void addStudentsGarades(int studentsNumber, 
                        std::map<std::string, std::vector<double> >& studentsGrades,
                        std::vector<std::string>& names,
                        std::vector<double>& grades) {
    std::string name;

    for (int i = 0; i < studentsNumber; i++) {
        std::cin >> name;
        double grade;
        std::cin >> grade;

        if (studentsGrades.find(name) == studentsGrades.end()) {

            studentsGrades[name] = grades;
            names.push_back(name);
        }

        studentsGrades[name].push_back(grade);
    }
}

void printSolution(std::map<std::string, std::vector<double> >& studentsGrades,
                   std::vector<std::string>& names,
                   std::vector<double>& grades) {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    for (int i = 0; i < names.size(); i++) {
        std::string name = names[i];
        grades = studentsGrades[name];
        double total = accumulate(grades.begin(), grades.end(), 0.0);
        double average = total / grades.size();

        std::cout << name << " -> ";
        for (int i = 0; i < grades.size(); i++) {
            std::cout << grades[i] << " ";
        }
        std::cout << "(avg: " << average << ")" << std::endl;

    }
}

int main() {
    int studentsNumber = readStudentsNumber();

    std::map<std::string, std::vector<double> > studentsGrades;
    std::vector<std::string> names;
    std::vector<double> grades;
    
    addStudentsGarades(studentsNumber, studentsGrades, names, grades);

    std::cout << std::endl;

    printSolution(studentsGrades, names, grades);

    return 0;
}
