#include <vector>

#include "Shape.h"
#include "2DShape.h"
#include "3DShape.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

int main() {
    /*Shape sh(5);

    sh.getArea();
    sh.print();*/


    /*TwoDShape twoDSh(7);
    twoDSh.getArea();
    twoDSh.print();
    twoDSh.position();
    twoDSh.fill();
    twoDSh.draw();*/


    /*ThreeDShape threeDSh(10, 17);
    threeDSh.getArea();
    threeDSh.print();
    threeDSh.getVolume();*/


    /*Circle c1(3);
    c1.getArea();
    c1.print();
    c1.position();
    c1.fill();
    c1.draw();*/

    /*Square sq1(5);
    sq1.getArea();
    sq1.print();
    sq1.position();
    sq1.fill();
    sq1.draw();*/

    /*Rectangle r1(5, 10);
    r1.getArea();
    r1.print();
    r1.position();
    r1.fill();
    r1.draw();*/

    Shape* twoDShapePtr1     = new TwoDShape(30);
    Shape* threeDShapePtr2   = new ThreeDShape(15, 20);
    Shape* circleShapePtr    = new Circle(3);
    Shape* squareSharePtr    = new Square(5);
    Shape* rectangleShapePtr = new Rectangle(5, 10);

    std::vector<Shape *> myShape { twoDShapePtr1 };
    myShape.push_back(threeDShapePtr2);
    myShape.push_back(circleShapePtr);
    myShape.push_back(squareSharePtr);
    myShape.push_back(rectangleShapePtr);

    for (size_t i = 0; i < myShape.size(); ++i) {
        myShape[i]->print();

        TwoDShape* twoDShape = dynamic_cast<TwoDShape*>(myShape[i]);
        if (twoDShape) {
            std::cout << "It's a TwoDShape." << std::endl;
            twoDShape->getArea();
            twoDShape->position();
            twoDShape->fill();
            twoDShape->draw();
            std::cout << std::endl;
        }

        ThreeDShape* threeDShape = dynamic_cast<ThreeDShape*>(myShape[i]);
        if (threeDShape) {
            std::cout << "It's a ThreeDShape." << std::endl;
            threeDShape->getArea();
            threeDShape->getVolume();
        }

        std::cout << std::endl;
    }

    return 0;
}
