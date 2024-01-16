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
        myShape[i]->getArea();
        std::cout << std::endl;
    }

    return 0;
}
