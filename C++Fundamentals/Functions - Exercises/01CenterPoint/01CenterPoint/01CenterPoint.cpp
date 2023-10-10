#include <iostream>
#include <cmath>
using namespace std;

void nearestPoint(double x1, double y1, double x2, double y2) {
	double firstAbs = (x1 * x1) + (y1 * y1);
	double secondAbs = (x2 * x2) + (y2 * y2);
	if (firstAbs > secondAbs) {
		cout << "(" << x2 << ", " << y2 << ")";
	}
	else {
		cout << "(" << x1 << ", " << y1 << ")";
	}
}

int main()
{
	double x1;
	double y1;
	double x2;
	double y2;

	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;

	nearestPoint(x1, y1, x2, y2);
}
