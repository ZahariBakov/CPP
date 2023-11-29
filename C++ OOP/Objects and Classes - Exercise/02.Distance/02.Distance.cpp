#include <iostream>
#include <cmath>
#include <iomanip>

class Points {
public:
    int x = 0;
    int y = 0;

    void readInput() {
        std::cin >> x >> y;
    }
};

double calculateDistances(int x1, int y1, int x2, int y2) {
    int x = x2 - x1;
    int y = y2 - y1;
    
    double result = sqrt((x * x) + (y * y));

    return result;
}

double round_to(double value, double precision)
{
    return std::round(value / precision) * precision;
}

int main() {
    Points firstPoint;
    firstPoint.readInput();

    Points secondPoint;
    secondPoint.readInput();

    double result = calculateDistances(firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y);

    std::cout << std::fixed << std::setprecision(3) << result << std::endl;

    return 0;
}
