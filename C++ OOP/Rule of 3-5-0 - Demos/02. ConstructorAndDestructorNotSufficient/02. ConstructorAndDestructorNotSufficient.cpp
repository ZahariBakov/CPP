#include <iostream>
#include <string>
#include <vector>

class Lecturer {
    static int NumLecturers;

    std::string name;
    double rating;
public:
    Lecturer(std::string name, double rating)
        : name(name), rating(rating) {
        NumLecturers++;
    }

    ~Lecturer() {
        NumLecturers--;
    }

    static int getNumLecturers() {
        return NumLecturers;
    }

    std::string getName() const {
        return this->name;
    }

    double getRating() const {
        return this->rating;
    }
};

int Lecturer::NumLecturers = 0;

void print(Lecturer lecturer) {
    std::cout << lecturer.getName() << " " << lecturer.getRating() << std::endl;
}

void showAndClearLecturers() {
    Lecturer a("Dandelion", 6.9),
        b("Geralt", 1.3),
        c("Yen", 4.2);

    std::cout << "Lecturers: " << Lecturer::getNumLecturers() << std::endl;

    std::vector<Lecturer> lecturers;
    lecturers.push_back(a);
    lecturers.push_back(b);
    lecturers.push_back(c);

    print(lecturers[0]);
    print(lecturers[1]);
    print(lecturers[2]);
}

int main() {
    showAndClearLecturers();

    std::cout << "Lecturers: " << Lecturer::getNumLecturers() << std::endl;

    return 0;
}
