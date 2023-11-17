#include <iostream>

int* findFirstNegativePtr(int numbers[], int lenght) {
    for (int i = 0; i < lenght; ++i) {
        if (numbers[i] < 0) {
            return &numbers[i];
        }
    }

    return nullptr;
}

int main() {
    int numbers[]{ 1, 5, -1, 12 }; // output: -1
    // int numbers[]{ 1, 5, 1, 12 };  // output: no negative numbers

    int* negativePtr = findFirstNegativePtr(numbers, 4);

    if (negativePtr != nullptr) {
        std::cout << *negativePtr << std::endl;
    }
    else {
        std::cout << "no negative numbers" << std::endl;
    }

    return 0;
}
