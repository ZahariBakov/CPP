#include <iostream> // Directly looks for system file iostream.
#include "Macros.h" // First looks for local file "01.Macros.h" - 
                    // if not found, searches for system file.

int main() {
    double radius;
    std::cin >> radius;

    std::cout << 3.14 << std::endl;

    SHOW(3.14 * radius * radius);

#undef SHOW
#define SHOW std::cout << "That's all, folks!" << std::endl;
    SHOW
#undef SHOW
    // The following line won't complete because SHOW is no longer defined
    // SHOW

    return 0;
}
