#include <iostream>
#include <string>

int main() { 
    char letter = 'A';

    void* voidPrt = &letter;
    char* charPtr = &letter;

    char* cStyleCstPtr = (char*)voidPrt;
    int* badCast = (int*)charPtr;

    std::cout << *cStyleCstPtr << std::endl; // prints 'A'

    // undefined behavior - takes sizeof(int) bytes starting from 'A'
    // and prints resulting number - could cause a memory error if those bytes
    // are outside the program's memory
    std::cout << *badCast << std::endl;

    // for void pointer, static cast is equivalent to C-Style cast
    char* staticCastPtr = static_cast<char*>(voidPrt);

    // static_cast here checks type and prevent compilatzion
    // (uncomment to see compilation error)
    // int* badStaticCastWintComplete = static_cast<int*>(charPtr);

    return 0;
}
