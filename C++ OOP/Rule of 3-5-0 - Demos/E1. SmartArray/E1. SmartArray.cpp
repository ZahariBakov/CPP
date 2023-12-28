#include <iostream>

// #include "SmartArray.h"
#include "SmartArrayWithPointers.h"

// Task: 
// - Implement a SmartArray<T> class that uses dynamic memory
//      - Must be RAII, but STL containers.smart pointers NOT allowed
//      - Has size, has index access (with operator[])
//      - Can be resized
//      - No support for copying/moving or assignment/move assignment
//
// - Bonus: even more RAII
//      - Don't use (directly) "new" in methods (negates the current restictions)
//
// - Bonus: enable iteration
// (e.g. with range-based for loop)

int main() {
    SmartArray<int> arr(5);
    arr[2] = 42;
    arr.print();

    arr.resize(10);
    arr.print();

    arr.resize(3);
    std::cout << "Custom range based for loop" << std::endl;

    for (const auto elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
