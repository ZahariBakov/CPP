#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

int main() {
    using namespace std;

/*
Read students in the following format:

4
Tony 2 5 5 3 6
George 2 2 3
Kerrigan 6 6 2 6 2 6
Jalina 6 6 5

Then reads commands in the following format:

George
Kerrigan
Zahari
end

... and prints the grades for each student on a single line
*/

    map<string, vector<int> > studenGrades;

    int numStudents;
    cout << "Enter students count: ";
    cin >> numStudents;

    // remove the endline from input
    // (after we read numStudents we're at the end of that line)
    cin.ignore();

    for (int i = 0; i < numStudents; i++)
    {
        string line;
        getline(cin, line);

        istringstream lineIn(line);
        string name;
        lineIn >> name;

        vector<int> grades;
        int grade;
        while (lineIn >> grade)
        {
            grades.push_back(grade);
        }

        studenGrades[name] = grades;
    }

    string command;
    getline(cin, command);

    while (command != "end")
    {
        cout << endl;

        map<string, vector<int> >::iterator gradesIt = studenGrades.find(command);

        if (gradesIt != studenGrades.end())
        {
            for (int grade : gradesIt->second)
            {
                cout << grade << " ";
            }
        }
        else
        {
            cout << "no info";
        }

        getline(cin, command);
    }
    cout << endl;

    return 0;
}
