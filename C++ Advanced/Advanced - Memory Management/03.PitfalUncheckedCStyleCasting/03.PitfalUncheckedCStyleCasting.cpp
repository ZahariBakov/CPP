#include <iostream>

int main() {
    char letter1 = 'a', letter2 = 'b', letter3 = 'c', letter4 = 'd';
    int* letter4Ptr = (int*)&letter1; // Here we access to 3 bytes of foreign memory. 

    *letter4Ptr = 842281524;

    std::cout << letter1 << letter2 << letter3 << letter4 << std::endl;

    return 0;
}
