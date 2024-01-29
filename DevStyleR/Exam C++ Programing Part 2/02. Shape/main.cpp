#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

#include <vector>

int main() {

    Shape* shape1 = new Shape(12.5);
    Shape* shape2 = new Circle(27.3);
    Shape* shape3 = new Rectangle(10.5, 15.8);

    //shape1->draw();
    //shape2->draw();
    //shape3->draw();

    std::vector<Shape*> shapesVec{ shape1, shape2 };
    shapesVec.push_back(shape3);

    for (auto shape : shapesVec) {
        shape->draw();
    }

    return 0;
}