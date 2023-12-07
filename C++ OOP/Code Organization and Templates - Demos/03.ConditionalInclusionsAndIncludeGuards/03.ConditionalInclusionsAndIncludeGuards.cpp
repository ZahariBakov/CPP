#include <iostream>
#include <cstdlib>

// NOTE: without the header guards, we would get a compilation error,
//       because HeaderGuardedFile define a functio, and
//       OtherFileAlsoIncludungHeaderGuardedFile included HeaderGuardedFile,
//       so the function would appear twice

#include "HeaderGuardedFile.h"
#include "OtherFileAlsoIncludingHeaderGuardedFile.h"

void clearScreen() {
    // NOTE: this demo does not intend to show the best way to clear the console
    // in a multi-platform way, but simply to demostrate the usage of ifdef
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif // _WIN32
}

#define PRECISION 2
// NOTE: uncomment one of the lines below and the calculations
//       will be done with float/int
//#define PRECISION 1 
//#define PRECISION 0 

int main() {
    std::cout << "some text that will be cleared immediately" << std::endl;
    clearScreen();

#if PRECISION == 2
#define PI 3.14159265359
    typedef double Number;
#elif PRECISION == 1
#define PI 3.14
    typedef float Number;
#else
#define PI 3
    typedef int Number;
#endif

    Number radius;
    std::cin >> radius;
    std::cout << radius * radius * PI << std::endl;

    return 0;
}
