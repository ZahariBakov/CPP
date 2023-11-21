#include <iostream>

int main() {
    int* arr = new int[3]; // This is how we allocate a one-dimensional array.


    // This is how we allocate a two-dimensional array.
    int** arr2D = new int* [3];
    for (int i = 0; i < 3; ++i) {
        arr2D[i] = new int[2];
    }

    arr2D[0][1];


    // This is how deleting memory for a two-dimensional array.
    for (int i = 0; i < 3; ++i) {
        delete[] arr2D[i];
        arr2D[i] = nullptr;
    }

    delete[] arr2D;
    arr2D = nullptr;

    return 0;
}
