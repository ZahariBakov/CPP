#include <iostream>

int main() {
    int number = 42;

    int* intPtr = &number;
    short int* shortIntPtr = (short int*)&number;
    char* charPtr = (char*)&number;

    std::cout << "intPtr:" << intPtr << " charPtr:" << (int*)charPtr << " shortIntPtr:" << shortIntPtr << std::endl;

    intPtr++; charPtr++; shortIntPtr++;
    std::cout << "intPtr:" << intPtr << " charPtr:" << (int*)charPtr << " shortIntPtr:" << shortIntPtr << std::endl;

    return 0;
}
