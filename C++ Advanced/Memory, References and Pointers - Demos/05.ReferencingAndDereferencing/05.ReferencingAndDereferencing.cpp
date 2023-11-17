#include <iostream>
#include <string>

int main() {
    int a = 42, b = 13;
    int* ptr = &a;                   // pointer to a variable 'a'
    std::cout << ptr << std::endl;   // this is pointer address
    std::cout << *ptr << std::endl;  // this is dereferencing pointer

    ptr = &b;                     // pointer to a variable 'b'
    *ptr = 7;                     // the pointer modifies the variable "b"
    std::cout << b << std::endl;  // print variable 'b' with new value

    std::string s = "world";
    std::string* sPtr = &s;
    sPtr->insert(0, "hello "); // makes s == "hello world"
    std::cout << *sPtr << std::endl;

    const char firstLetter = (*sPtr)[0]; // dereferencing a poiner 'sPtr' and taking the first element of the string
    const char secondLetter = sPtr->at(1); // Same as above but slower because it checks for errors.
    std::cout << firstLetter << std::endl;
    std::cout << secondLetter << std::endl;

    return 0;
}
