#include "Discipline.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"
#include "School.h"

int main() {
    // Create disciplines
    Discipline math("Math", 20, 10);
    Discipline physics("Physics", 15, 8);
    Discipline history("History", 45, 69);

    // Create teachers
    Teacher teacher1("John Doe", "Professor", { math, physics });
    Teacher teacher2("Alice Smith", "Assistant Professor", { math, history });

    // Create students
    Student student1("Bob", 1);
    Student student2("Emma", 2);

    // Create classes
    Class class1("ClassA", { teacher1, teacher2 }, { student1, student2 });

    // Create school
    School school({ class1 });

    // Print sample school information
    std::cout << "School Information:\n";
    for (const auto& schoolClass : school.getClasses()) {
        std::cout << "Class Identifier: " << schoolClass.getIdentifier() << "\n";
        for (const auto& teacher : schoolClass.getTeachers()) {
            std::cout << "  Teacher: " << teacher.getName() << ", Title: " << teacher.getTitle() << "\n";
            for (const auto& discipline : teacher.getDisciplines()) {
                std::cout << "    Discipline: " << discipline.getName() << ", Lectures: "
                    << discipline.getNumLectures() << ", Exercises: " << discipline.getNumExercises() << "\n";
            }
        }
        for (const auto& student : schoolClass.getStudents()) {
            std::cout << "  Student: " << student.getName() << ", Class Number: " << student.getClassNumber() << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
