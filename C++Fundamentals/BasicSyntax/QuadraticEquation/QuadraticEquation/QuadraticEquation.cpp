#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, discriminant, x1, x2;

    cin >> a >> b >> c;

    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << x1 << " " << x2 << endl;
    }
    else {
        if (discriminant == 0) {
            x1 = -b / (2 * a);
            cout << x1 << endl;
        }
        else {
            cout << "no roots" << endl;
        }
    }
}
