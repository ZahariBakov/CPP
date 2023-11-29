#include <iostream>
#include <string>
#include <sstream>

class Person {
    class Body {
    private:
        double heightMeters;
        double weightKgs;

    public:
        Body(double heightMeters, double weightKgs)
            : heightMeters(heightMeters), weightKgs(weightKgs) {
        }

        void increaseWeight(double kgs) {
            this->weightKgs += kgs;
        }

        std::string getInfo() {
            std::ostringstream info;
            info << ", height: " << this->heightMeters << ", weight: " << this->weightKgs;
            return info.str();
        }
    };

private:
    std::string name;
    int age = 0;
    Body body;

public:
    Person()
        : body(0, 0) {
    }

    Person(std::string name, int age, double heightMeters, double weightKgs)
        : name(name), age(age), body(heightMeters, weightKgs) {
    }

    std::string getName() {
        return this->name;
    }

    void makeOlder(int years) {
        if (years < 0) {
            throw "yaers must be a positive number";
        }

        this->age += years;
    }

    void makeHavier(double kgs) {
        if (kgs < 0) {
            throw "kgs must be a positive number";
        }

        this->body.increaseWeight(kgs);
    }

    std::string getInfo() {
        std::ostringstream info;
        info << "name: " << this->name << ", age: " << this->age << this->body.getInfo();

        return info.str();
    }
};

int main() {
    Person p("Enca Psulation", 31, 1.82, 82);

    std::cout << p.getInfo() << std::endl;

    p.makeHavier(25);
    p.makeOlder(21);

    std::cout << "Some time has passed for " << p.getName()
        << "... and he's a bit out of shape now" << std::endl;

    std::cout << p.getInfo() << std::endl;

    return 0;
}
