#include <iostream>

void changeSecondValueTo(int* arr, int value) {
    int innerArray[2]{ 1, 2 };
    arr = innerArray;
    arr[1] = value;
}

int main() {
    const int size = 3;
    int arr[size] = { 13, 42, 69 };

    std::cout << 1[arr] << std::endl;
    std::cout << arr[1] << std::endl;

    changeSecondValueTo(arr, 7);
    std::cout << arr[1] << std::endl;

    return 0;
}
