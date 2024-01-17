#include "Shape.h"
#include "2DShape.h"
#include "3DShape.h"

#include <vector>

int main() {
    /*Shape sh(5);

    sh.getArea();
    sh.print();

    std::cout << std::endl;

    TwoDShape twoDSh(7);
    twoDSh.getArea();
    twoDSh.print();

    std::cout << std::endl;

    ThreeDShape threeDSh(10, 17);
    threeDSh.getArea();
    threeDSh.print();
    threeDSh.getVolume();*/

    Shape* sPtr1 = new TwoDShape(30);
    Shape* sPtr2 = new ThreeDShape(15, 20);

    std::vector<Shape *> myShape { sPtr1 };
    myShape.push_back(sPtr2);

    for (size_t i = 0; i < myShape.size(); ++i) {
        myShape[i]->print();

        TwoDShape* twoDShape = dynamic_cast<TwoDShape*>(myShape[i]);
        if (twoDShape) {
            std::cout << "It's a TwoDShape." << std::endl;
            twoDShape->getArea();
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
