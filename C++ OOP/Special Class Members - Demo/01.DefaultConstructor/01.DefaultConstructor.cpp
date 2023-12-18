#include <iostream>
#include <string>
#include <vector>

class Lecturer {
    double rating = 0;
    std::string name;
public:
    Lecturer() {
        std::cout << "Lecturer default ctor BODY" << std::endl;
    }
};

class Lesson {
    Lecturer lecturer;
    std::string subject;
    int numStudents = 0;
public:
    Lesson() {
        std::cout << "Lesson default ctor BODY" << std::endl;
    }

    Lesson(const Lesson& other)
        : lecturer(other.lecturer), subject(other.subject), numStudents(other.numStudents) {
        std::cout << "Lesson COPY ctor BODY" << std::endl;
    }

    Lesson operator=(const Lesson& other) {
        lecturer = other.lecturer;
        subject = other.subject;
        numStudents = other.numStudents;

        std::cout << "Lesson COPY assigment operator BODY" << std::endl;
        return *this;
    }
};

// RVO - Return Value Optimization
Lecturer produceLecturer() {
    Lecturer lecturer;
    return lecturer;
}

int main() {
    Lesson lesson;
    std::cout << "--------------------------" << std::endl;
    Lesson lesson2 = Lesson();
    std::cout << "--------------------------" << std::endl;
    Lesson lesson3;
    std::cout << "--------------------------" << std::endl;
    lesson2 = lesson3;
    std::cout << "--------------------------" << std::endl;
    const auto lecturer = produceLecturer();

    return 0;
}
