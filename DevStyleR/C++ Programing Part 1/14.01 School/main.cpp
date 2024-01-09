#include <iostream>

#include "Discipline.h"
#include "Teacher.h"

int main() {
    Discipline disp("History", 45, 69);

    Teacher firstTeacher("Ivan Ivanov", "Mr.", disp);

    firstTeacher.printTeacherInfo();

    return 0;
}
