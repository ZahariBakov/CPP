#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

const double pi = M_PI;

class Shape {
public:
    // Virtual member function to calculate the area
    virtual double calculateArea() const = 0;

    // Virtual member function to calculate the perimeter
    virtual double calculatePerimeter() const = 0;
};

class Circle : public Shape {
private: double radius;

public:
    // Constructor
    Circle(double rad) : radius(rad) {}

    // Functions
    double calculateArea() const override {
        return pi * pow(radius, 2);
    }

    double calculatePerimeter() const override {
        return 2 * pi * radius;
    }
};

class Rectangle : public Shape {
private: double length;
       double width;

public:
    // Constructor
    Rectangle(double len, double wid) : length(len),
        width(wid) {}

    // Functions
    double calculateArea() const override {
        return length * width;
    }

    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private: double side1;
       double side2;
       double side3;

public:
    // Constructor
    Triangle(double s1, double s2, double s3) : side1(s1),
        side2(s2),
        side3(s3) {}

    // Functions
    double calculateArea() const {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(7.0);
    Rectangle rectangle(4.2, 8.0);
    Triangle triangle(4.0, 4.0, 3.2);

    std::cout << "Circle: " << "\n";
    std::cout << "Area: " << circle.calculateArea() << "\n";
    std::cout << "Perimeter: " << circle.calculatePerimeter() << "\n\n";

    std::cout << "Rectangle: " << "\n";
    std::cout << "Area: " << rectangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << "\n\n";

    std::cout << "Triangle: " << "\n";
    std::cout << "Area: " << triangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;

    return 0;
}
