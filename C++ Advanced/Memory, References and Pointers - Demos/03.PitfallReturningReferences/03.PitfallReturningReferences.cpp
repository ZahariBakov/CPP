#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> generateRoots(int toNumber) {
    std::vector<int> roots;

    for (int i = 0; i < toNumber; ++i) {
        roots.push_back(sqrt(i));
    }

    return roots;
}

int main() {
    // NOTE: it is possible that this code will seem to work as expected,
    // as the program is short and the memory could still remain the same
    // even after being freed. But it is not quaranteed to work, especially
    // in a real, non=debug enviroment, where the memory freed by the vector
    // is likley to be overwritten at some point by another program, or even
    // the same program
    std::vector<int> rootsRef = generateRoots(100);

    // NOTE 2: this itherVector is here to simulate a real enviromnt, where
    // additional memory allocations might overwrite the freed memory. Under
    // Windows, in Code::Blocks with MinGW this otherVector seem to overwrite that memory,
    // making the printed value different. But it is not 100% quaranted, especiall
    // if we change the eniroment or the compiler. This is exactly why the behavior
    // is "undefined" - we cannot be sure what will happen, because the C++ standard
    // does not place a strict requirement on what should happed, hence different
    // compilers can create code that behaves differently in different situations
    std::vector<int> otherVector{ 42, 13, 69 };

    std::cout << generateRoots(100)[4] << std::endl;

    std::cout << &rootsRef;

    return 0;
}
