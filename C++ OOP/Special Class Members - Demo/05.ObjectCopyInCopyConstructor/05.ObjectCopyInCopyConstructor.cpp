#include <iostream>
#include <string>

struct Lecturer {
    double rating;
    std::string name;

    Lecturer(std::string name, double rating)
        : rating(rating), name(name) {
    }

    Lecturer(const Lecturer &other) {
        *this = other;
    }

    Lecturer& operator=(Lecturer other) {
        this->name = other.name;
        this->rating = other.rating;

        return *this;
    }
};

int main() {
    Lecturer a("Bill", 4.2);
    Lecturer other(a);

    std::cout << other.name << std::endl;

    return 0;
}
