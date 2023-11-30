#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    void readStudent() {
        std::cin >> name >> surname >> average;
    }

    double getGrade() const {
        return average;
    }

    std::string getNames() const {
        return (name + " " + surname);
    }

private:
    std::string name;
    std::string surname;  
    double average;
};

class ClassOfStudents {
public:
    void readInput() {
        std::cin >> studentsCount;
        
        for (int i = 0; i < studentsCount; ++i) {
            Student student;
            student.readStudent();
            averageGradeOfStudents += student.getGrade();
            students.push_back(student);
        }
    }

    void printStudents() {
        if (students.empty()) {
            std::cout << "Invalid input" << std::endl;
        }
        else {
            for (const Student& student : students) {
                std::cout << student.getNames() << " " << student.getGrade() << std::endl;
            }

            std::cout << (averageGradeOfStudents / studentsCount) << std::endl;
        }
    }

private:
    int studentsCount = 0;
    double averageGradeOfStudents = 0.0;

    std::vector<Student> students;
};

int main() { 
    ClassOfStudents allStudents;

    allStudents.readInput();
    allStudents.printStudents();

    return 0;
}
