#include <iostream>
#include <cmath>

void f() {

}

int main() {
    int x = 42;
    auto addressX = &x;

    std::cout << x << " at " << addressX << std::endl;

    printf("f() code at %p\n", (void*)&f);

    // NOTE: there are different abs functions (int, double...), so we specify
    // we want the one returning double and accepting 1 double parameter
    double(&absAddress)(double) = abs;
    printf("abs(double) code at %p\n", (void*)absAddress);

    return 0;
}
