#include <iostream>
#include <string>
#include <vector>

class Lecturer {
    double rating;
    std::string name;
public:
    Lecturer() : rating(0) {
    }

    Lecturer(std::string name, double rating)
        : rating(rating), name(name) {
    }

    Lecturer(const Lecturer& other)
        : rating(other.rating), name(other.name) {
        std::cout << "Lecturer COPY ctor BODY" << std::endl;
    }

    Lecturer& operator=(const Lecturer& other) {
        this->rating = other.rating;
        this->name = other.name;

        std::cout << "Lecturer COPY-ASSING operator BODY" << std::endl;

        return *this;
    }

    std::string getName() const {
        return this->name;
    }

    double getRating() {
        return this->rating;
    }
};

class Lesson {
    Lecturer lecturer;
    std::string subject;
    int numStudents;
public:
    Lesson(Lecturer lecturer, std::string subject, int numStudents)
        : lecturer(lecturer), subject(subject), numStudents(numStudents) {
    }

    Lesson() {
    }

    Lesson(const Lesson& other)
        : lecturer(other.lecturer), subject(other.subject), numStudents(other.numStudents) {
        std::cout << "Lesson COPY ctor BODY" << std::endl;
    }

    Lecturer getLecturer() const {
        return this->lecturer;
    }

    std::string getSubject() const {
        return this->subject;
    }

    int getNumStudents() const {
        return this->numStudents;
    }

    Lesson& operator=(const Lesson& other) {
        this->lecturer = other.lecturer;
        this->subject = other.subject;
        this->numStudents = other.numStudents;

        return *this;
    }
};

// (const Lesson &lessonCopy)
void printLesson(Lesson lessonCopy) {
    std::cout << lessonCopy.getSubject() << std::endl << "attended by "
        << lessonCopy.getNumStudents() << std::endl << "lecturer: "
        << lessonCopy.getLecturer().getName() << " ("
        << lessonCopy.getLecturer().getRating() << "/10)" << std::endl;
}

int main() {
    Lecturer lecturer("Joro", 6.9);
    std::cout << "--------------------------------------" << std::endl;
    Lesson lesson1(lecturer, "Pointers and references", 5);
    std::cout << "--------------------------------------" << std::endl;
    Lesson copy = lesson1;
    std::cout << "--------------------------------------" << std::endl;
    printLesson(lesson1);


    return 0;
}
