#include <iostream>

int main() {
    int arr[3]{ 13, 42, 69 };
    int* p = arr;
    p[1] = -42;

    std::cout << arr[1] << std::endl;
    std::cout << *(p + 1) << std::endl;
    std::cout << p[1] << std::endl;

    int arr2D[2][2]{
        {1, 2},
        {3, 4}
    };

    // This is not good practice:
    std::cout << *(*(arr2D + 1) + 1) << std::endl;

    // Same but easier to reed:
    std::cout << arr2D[1][1] << std::endl;

    return 0;
}
